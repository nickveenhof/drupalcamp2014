<?php
/**
 * @file
 * gent2014_user_register.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gent2014_user_register_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
