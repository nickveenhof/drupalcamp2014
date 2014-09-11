<?php
/**
 * @file
 * gent2014_session.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function gent2014_session_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|schedule_item|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'schedule_item';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'session_room' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|schedule_item|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|session|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'session';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'session_room' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|session|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function gent2014_session_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'session_room';
  $ds_field->label = 'Session Room';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '  <?php
  $sql = db_select(\'cod_event_room\', \'room\');
  $sql->addField(\'room\', \'name\');
  $sql->innerJoin(\'field_data_field_timeslot_room\', \'tsroom\', \'tsroom.field_timeslot_room_target_id = room.evtrid\');
  $sql->innerJoin(\'field_data_field_session_timeslot\', \'slot\', \'slot.field_session_timeslot_target_id = tsroom.entity_id\');
  $sql->innerJoin(\'node\', \'n\', \'slot.revision_id = n.vid\');
  $sql->condition(\'n.nid\', $entity->nid);
  $name = $sql->execute()->fetchAssoc(\'name\');
  return !empty($name) ? $name[\'name\'] : t(\'No room assigned yet\');
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['session_room'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function gent2014_session_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|schedule_item|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'schedule_item';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'session_room',
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'session_room' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|schedule_item|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|session|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'session';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'session_room',
        1 => 'field_experience',
        2 => 'og_vocabulary',
        3 => 'title',
        4 => 'field_speakers',
        5 => 'body',
        6 => 'node_link',
      ),
    ),
    'fields' => array(
      'session_room' => 'ds_content',
      'field_experience' => 'ds_content',
      'og_vocabulary' => 'ds_content',
      'title' => 'ds_content',
      'field_speakers' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|session|teaser'] = $ds_layout;

  return $export;
}
