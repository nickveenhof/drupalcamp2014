<?php

/**
 * Default Program page (without flags).
 *
 * @param String $day
 *   String indication of which event-day (friday or saturday).
 *
 * @return String
 */
function gent2014_session_schedule_default_page($day) {
  drupal_set_title('Schedule');
  $output = _gent2014_session_schedule_create_page($day);

  if (!$output) {
    $text = t('At the moment, there are no sessions accepted for this day.');

    // Create message
    $output = theme('html_tag', array(
      'element' => array(
        '#tag'        => 'div',
        '#value'      => '<p>' . $text . '</p>',
        '#attributes' => array('class' => drupal_html_class('conf-message')),
      )
    ));
  }

  return $output;
}

/**
 * Create program/schedule page.
 *
 * @param String $day
 *   String indication of which event-day (friday or saturday).
 *
 * @return bool|string
 */
function _gent2014_session_schedule_create_page($day) {
  // @TODO: Create a DrupalCamp dashboard or something.

  // Timeslots. Hardcoded. Punch me if you see me.
  /**
                __________                  __,___/  ",",
         ___.--"          "\'.         ____/  l   \    ",'-,
  ------f"               // \\\        \  (l\ \    \     \ \",
        |                    |||       /   u       |      \ \ \
        |                    |||     _ )          /       | |  \
    ----L_-XXX-.             .|'    / U          <        | |  |
                "\   -<_____///     \           6 )       | |  |
                  \___)     -"       '.       -.<"       / /   |
                                      |'.___  |       _._."   /
                                      |     ./     _."."   _."
                                     /      |"----"     _."
                                  jjs       \
   */
  $available_days = array(
    'friday'   => '2014-11-07',
    'saturday' => '2014-11-08'
  );

  // Even worse. Rooms by their human-readable name. Used to display the schedule.
  // Set to FALSE = display on the left side of the timeline, TRUE = on the right side.
  $room_mapping = array(
    'Calibrate Club' => TRUE,
    'EntityOne Lodge' => FALSE,
  );

  if (empty($available_days[$day])) {
    return FALSE;
  }

  // Retrieve all timeslots for a given day.
  $timeslots = _gent2014_session_page_get_timeslots($available_days[$day]);

  $output = array();

  foreach ($timeslots as $timeslot) {
    $nids = _gent2014_session_page_get_nodes($timeslot);

    if (empty($nids)) {
      continue;
    }

    $output[$timeslot->starttime] = array(
      'nids'      => $nids,
      'starttime' => $timeslot->starttime,
      'endtime'   => $timeslot->endtime,
    );
  }

  $return = '';
  if (!empty($output)) {
    $items = array();
    foreach ($output as $row) {
      $items[] = array(
        'data'  => '<div class="tldate">' . strtoupper(format_date(strtotime($row['starttime']) + 3600, 'custom', 'D  d/m/Y - H:i')) . ' - ' . strtoupper(format_date(strtotime($row['endtime']) + 3600, 'custom', 'H:i')) . '</div>',
        'class' => array('tldate'),
      );

      foreach ($row['nids'] as $nid) {

        // Load entities.
        $entity = node_load($nid->nid);
        $class  = '';

        if ($entity->type == 'session') {
          $room = _gent2014_session_get_room_name($nid->nid);
          if ($room_mapping[$room]) {
            $class = 'timeline-inverted';
          }
        }

        // Get teaser view of entities.
        $node    = entity_view('node', array($entity), 'teaser');
        $items[] = array(
          'data'  => '<div class="timeline-panel">' . render($node) . '</div>',
          'class' => array($class ? $class : '', ($entity->type == 'schedule_item') ? 'schedule-item' : ''),
        );
      }
    }

    $return .= theme('item_list', array('items' => $items, 'attributes' => array('class' => array('timeline'))));

    return $return;
  }
  else {
    return FALSE;
  }
}

/**
 * Helper function to retrieve the name of the room a session is scheduled in.
 *
 * @param  int $nid
 *
 * @return string
 */
function _gent2014_session_get_room_name($nid) {
  $sql = db_select('cod_event_room', 'room');
  $sql->addField('room', 'name');
  $sql->innerJoin('field_data_field_timeslot_room', 'tsroom', 'tsroom.field_timeslot_room_target_id = room.evtrid');
  $sql->innerJoin('field_data_field_session_timeslot', 'slot', 'slot.field_session_timeslot_target_id = tsroom.entity_id');
  $sql->innerJoin('node', 'n', 'slot.revision_id = n.vid');
  $sql->condition('n.nid', $nid);

  $name = $sql->execute()->fetchAssoc('name');

  return $name['name'];
}

/**
 * Helper function to retrieve timeslots on a day.
 *
 * @param  string $date
 *
 * @return QueryResult
 */
function _gent2014_session_page_get_timeslots($date) {
  $date  = $date . '%';
  $query = db_select('cod_event_time', 'evt');

  $query->addField('evt', 'evttid', 'entity_id');
  $query->addField('evt_date', 'field_evttime_date_value', 'starttime');
  $query->addField('evt_date', 'field_evttime_date_value2', 'endtime');

  $query->innerJoin('field_data_field_evttime_date', 'evt_date', 'evt_date.revision_id = evt.evttid');

  $query->condition('evt_date.field_evttime_date_value', $date, 'LIKE');

  $query->orderBy('evt_date.field_evttime_date_value');

  return $query->execute()->fetchAll();
}

/**
 * Get all sessions for a specific day.
 *
 * @param string $timeslot
 */
function _gent2014_session_page_get_nodes($timeslot) {
  // Get all session of the given day
  $query = db_select('node', 'node')->distinct();

  $query->addField('node', 'nid', 'nid');

  $query->innerJoin('field_data_field_session_timeslot', 'session_slot', 'session_slot.entity_id = node.nid');
  $query->innerJoin('field_data_field_timeslot_time', 'timeslot_time', 'timeslot_time.revision_id = session_slot.field_session_timeslot_target_id');
  $query->leftJoin('field_data_field_accepted', 'accepted', 'accepted.entity_id = node.nid');
  $query->leftJoin('field_data_field_timeslot_room', 'room', 'room.entity_id = timeslot_time.entity_id');

  $query->condition('timeslot_time.field_timeslot_time_target_id', $timeslot->entity_id);
  $query->condition('node.status', 1);
  $query->where('((accepted.field_accepted_value = \'accepted\' AND node.type = \'session\') OR (node.type = \'schedule_item\'))');

  return $query->execute()->fetchAllAssoc('nid');
}
