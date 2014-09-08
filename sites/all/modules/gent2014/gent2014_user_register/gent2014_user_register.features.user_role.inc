<?php
/**
 * @file
 * gent2014_user_register.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function gent2014_user_register_user_default_roles() {
  $roles = array();

  // Exported role: unconfirmed user.
  $roles['unconfirmed user'] = array(
    'name' => 'unconfirmed user',
    'weight' => 6,
  );

  return $roles;
}
