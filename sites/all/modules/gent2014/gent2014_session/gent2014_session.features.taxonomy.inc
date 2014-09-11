<?php
/**
 * @file
 * gent2014_session.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function gent2014_session_taxonomy_default_vocabularies() {
  return array(
    'session_tracks_1' => array(
      'name' => 'Session Tracks (DrupalCamp Ghent)',
      'machine_name' => 'session_tracks_1',
      'description' => 'Tracks organize DrupalCamp Ghent sessions by topic.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
