<?php
/**
 * @file
 * gent_2014_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gent_2014_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
