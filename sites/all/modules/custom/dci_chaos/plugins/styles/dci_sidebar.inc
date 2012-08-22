<?php


/**
 * @file
 * Definition of the 'list' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Drupal Camp Indonesia Sidebar'),
  'description' => t('Presents the panes in the form of an HTML list.'),
  'render region' => 'panels_dci_sidebar_render_region',
);

/**
 * Render region callback.
 */
function theme_panels_dci_sidebar_render_region($vars) {
  $region_id = $vars['region_id'];
  $panes = $vars['panes'];

  $output = '<aside class="'. $region_id . '">';

  foreach ($panes as $pane_id => &$item) {
    $output .= '<section>' . $item . '</section>';
  }
  $output .= '</aside>';

  return $output;
}
