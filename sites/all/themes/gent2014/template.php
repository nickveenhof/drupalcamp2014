<?php

/**
 * Implements template_preprocess_field().
 *
 * @param  array $variables [description]
 * @param  string $hook      [description]
 */
function gent2014_preprocess_field(&$variables, $hook) {
  if ($variables['element']['#field_name'] == 'field_experience' && ($variables['element']['#view_mode'] == 'teaser' || $variables['element']['#view_mode'] == 'taxonomy_page_overview')) {
    $variables['classes_array'][] = 'experience-level';
    foreach ($variables['element']['#items'] as $item) {
      $variables['classes_array'][] = 'experience-level-' . $item['value'];
    }
  }
  elseif ($variables['element']['#field_name'] == 'og_vocabulary' && $variables['element']['#bundle'] == 'session' && $variables['element']['#view_mode'] == 'teaser') {
    foreach ($variables['element']['#items'] as $key => $item) {
      if (!empty($item['entity'])) {
        $colors = field_get_items('taxonomy_term', $item['entity'], 'field_track_color');
        if (!empty($colors) && !empty($colors[0]['rgb'])) {
          $rgb = $colors[0]['rgb'];
          $variables['item_attributes_array'][$key]['style'] = 'background: ' . $rgb;
        }
      }
    }
  }
  elseif ($variables['element']['#field_name'] == 'title' && $variables['element']['#bundle'] == 'schedule_item') {
    $node = $variables['element']['#object'];
    $type = field_get_items('node', $node, 'field_schedule_item_type');

    if (empty($type) || empty($type[0]['value'])) { return; }

    $variables['classes_array'][] = 'schedule_item';
    $variables['classes_array'][] = 'schedule_' . check_plain($type[0]['value']);
  }
}
