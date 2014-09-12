<?php

/**
 * Implements template_preprocess_field().
 *
 * @param  array $variables [description]
 * @param  string $hook      [description]
 */
function gent2014_preprocess_field(&$variables, $hook) {
  if ($variables['element']['#field_name'] == 'field_experience') {
    $variables['classes_array'][] = 'experience-level';
    foreach ($variables['element']['#items'] as $item) {
      $variables['classes_array'][] = 'experience-level-' . $item['value'];
    }
  }
  elseif ($variables['element']['#field_name'] == 'og_vocabulary' && $variables['element']['#bundle'] == 'session') {
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
  // elseif ($element['#field_name'] == 'field_session_track') {
  //   foreach ($variables['items'] as $delta => $item) {
  //     if (empty($item['#options']['entity'])) {
  //       continue;
  //     }
  //     $colors = field_get_items('taxonomy_term', $item['#options']['entity'], 'field_track_color_code');
  //     if (!empty($colors) && !empty($colors[0]['rgb'])) {
  //       $rgb = $colors[0]['rgb'];
  //       // $rgb = str_replace('#', '', $rgb);
  //       $variables['item_attributes_array'][$delta]['style'] = 'background: ' . $rgb;
  //     }
  //   }
  // }
}
