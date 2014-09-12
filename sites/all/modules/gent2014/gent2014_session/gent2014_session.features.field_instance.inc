<?php
/**
 * @file
 * gent2014_session.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function gent2014_session_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-session_tracks_1-field_track_color'
  $field_instances['taxonomy_term-session_tracks_1-field_track_color'] = array(
    'bundle' => 'session_tracks_1',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'color_field',
        'settings' => array(),
        'type' => 'color_field_default_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_track_color',
    'label' => 'Track Color',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_default_widget',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Track Color');

  return $field_instances;
}
