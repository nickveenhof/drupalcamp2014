<?php
/**
 * @file
 * cod_schedule.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cod_schedule_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view schedule'.
  $permissions['view schedule'] = array(
    'name' => 'view schedule',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'cod_schedule',
  );

  return $permissions;
}
