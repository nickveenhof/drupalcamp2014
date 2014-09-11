<?php

/**
 * Default Program page (without flags).
 */
function gent2014_session_schedule_default_page($day) {
  drupal_set_title('Schedule');
  $output = _gent2014_session_schedule_create_page($day);

  if (!$output) {
    $text = t('At the moment, there are no sessions accepted for this day.');

    // Create message
    $output = theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#value' => '<p>' . $text . '</p>',
        '#attributes' => array('class' => drupal_html_class('conf-message')),
      )
    ));
  }

  return $output;
}

/**
 * Create program/schedule page.
 */
function _gent2014_session_schedule_create_page($day, $favorite = FALSE) {
  $available_days = array(
    'friday' => '2014-11-07', 
    'saturday' => '2014-11-08'
  );

  if (empty($available_days[$day])) {
    return FALSE;
  }

  drupal_add_js(drupal_get_path('module', 'gent2014_session') . '/js/jquery.timelinr-0.9.54.js');
  drupal_add_css(drupal_get_path('module', 'gent2014_session') . '/css/style.css');

  // Get nids of all sessions
  $timeslots = _gent2014_session_page_get_timeslots($available_days[$day]);

  $timezone = new DateTimeZone('Europe/Brussels');

  $output = array();
  $dates = array();

  foreach ($timeslots as $timeslot) {
    $nids = _gent2014_session_page_get_nodes($timeslot, $favorite);

    if (empty($nids)) {
      continue;
    }

    // Load entities
    $entities = node_load_multiple(array_keys($nids));

    // Get teaser view of entities
    $nodes = entity_view('node', $entities, 'teaser');

    $dateTime = new DateTime($timeslot->starttime, $timezone);
    $offset = $timezone->getOffset($dateTime);

    $output[$timeslot->starttime] = render($nodes);
  }

  // dsm($output);

$return = '';
  if (!empty($output)) {
    $items = array();

    $date_items = array();

    foreach ($output as $timeslot => $row) {
      $date_items[] = array(
        'data' => l(
          $timeslot, 
          '', 
          array(
            'fragment' => preg_replace('/[^\da-z]/i', '', $timeslot),
            'external' => FALSE,
            'attributes' => array(
              'title' => $timeslot
            ),
          )
        ), 
      );
      $items[] = array(
        'data' => $row,
        'id' => preg_replace('/[^\da-z]/i', '', $timeslot),
      );
    }

    $return .= theme('item_list', array('items' => $date_items, 'attributes' => array('id' => 'dates')));
    $return .= theme('item_list', array('items' => $items, 'attributes' => array('id' => 'issues')));
    $return .= '
    <div id="grad_left"></div>
    <div id="grad_right"></div>
    <a href="#" id="next">+</a>
    <a href="#" id="prev">-</a>';

    return theme('html_tag', array(
      'element' => array(
        '#tag' => 'div',
        '#attributes' => array('id' => drupal_html_id('timeline')),
        '#value' => $return,
      ),
    ));

  }
  else {
    return FALSE;
  }
}

function _gent2014_session_page_get_timeslots($date) {
  $date = $date . '%';
  $query = db_select('cod_event_time', 'evt');

  $query->addField('evt', 'evttid', 'entity_id');
  $query->addField('evt_date', 'field_evttime_date_value', 'starttime');

  $query->innerJoin('field_data_field_evttime_date', 'evt_date', 'evt_date.revision_id = evt.evttid');

  $query->condition('evt_date.field_evttime_date_value', $date, 'LIKE');
 
  $query->orderBy('evt_date.field_evttime_date_value');

  // dsm($date);

  return $query->execute()->fetchAll();
}

/**
 * Get all sessions for a specific day.
 */
function _gent2014_session_page_get_nodes($timeslot, $favorite) {
  global $user;

  // Get all session of the given day
  $query = db_select('node', 'node')->distinct();

  $query->addField('node', 'nid', 'nid');

  $query->innerJoin('field_data_field_session_timeslot', 'session_slot', 'session_slot.entity_id = node.nid');

  $query->innerJoin('field_data_field_timeslot_time', 'timeslot_time', 'timeslot_time.revision_id = session_slot.field_session_timeslot_target_id');

  $query->condition('timeslot_time.field_timeslot_time_target_id', $timeslot->entity_id);


  // $query->innerJoin('field_data_field_event_timeslots', 'timeslot', 'timeslot.entity_id = node.nid');





  // $query->innerJoin('field_data_field_slot_types_time_slot', 'time_slot', 'time_slot.entity_id = timeslot.field_session_timeslot_target_id');
// var_dump($query->__toString());
  // $query->innerJoin('field_data_field_slot_datetime', 'datetime', 'datetime.entity_id = time_slot.field_slot_types_time_slot_target_id');
  // $query->innerJoin('og_membership', 'og', 'og.etid = datetime.entity_id');
  // $query->innerJoin('field_data_field_accepted', 'accepted', 'accepted.entity_id = node.nid');
  // $query->condition('og.gid', $day);
  // $query->condition('node.status', 1);
  // $query->condition('accepted.field_accepted_value', 1);
  // $query->condition('datetime.field_slot_datetime_value', $timeslot);
  // // $query->where('DATE(datetime.field_slot_datetime_value) = ' . $date_day);
  // // $query->groupBy('datetime.field_slot_datetime_value');
  // $query->orderBy('datetime.field_slot_datetime_value');

  // // dsm($query->__toString());
  // // dsm($timeslot);

  // // If we only want bookmarked session.
  // if ($favorite) {
  //   $query->innerJoin('flag_content', 'flag_content', 'flag_content.content_id = node.nid');
  //   $query->innerJoin('flags', 'flags', 'flags.fid = flag_content.fid');
  //   $query->condition('flags.name', 'session_schedule');
  //   $query->condition('flag_content.uid', $user->uid);
  // }

  return $query->execute()->fetchAllAssoc('nid');
}