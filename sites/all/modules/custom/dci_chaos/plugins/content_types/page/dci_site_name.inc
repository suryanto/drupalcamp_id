<?php

/**
 * @file
 * Plugin to handle the 'page_site_name' content type which allows the
 * site_name of the site to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('DCI html site name'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('The name of the site.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

/**
 * Output function for the 'page_site_name' content type.
 *
 * Outputs the site_name for the current page.
 */
function dci_chaos_dci_site_name_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();

  $names = explode(' ', check_plain(variable_get('site_name', 'Drupal')), 3);

  // Gets "Drupal".
  $site_name = $names[0];
  if (isset($names[1])) {
    // Gets the event "Camp".
    $site_name .= ' <span class="site-event">' . $names[1] . '</span>';
    // Gets the region "Indonesia", and whatever left of the string xD .
    if (isset($names[2])) {
      $site_name .= ' <span class="site-regional">' . $names[2] . '</span>';
    }
  }

  $block->content = $site_name;

  return $block;
}
