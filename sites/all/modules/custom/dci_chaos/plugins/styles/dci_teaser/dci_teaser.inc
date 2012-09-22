<?php

/**
 * HTML header panels wrapper.
 */

// Plugin definition
$plugin = array(
  'title' => t('Drupal Camp Indonesia Teaser'),
  'description' => t('Renders article as teaser.'),
  'render pane' => 'dci_teaser_render_pane',
  'css' => 'dci_teaser.css',
);

/**
 * Render pane callback.
 */
function theme_dci_teaser_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }
  $pane = $vars['pane'];

  drupal_add_css(drupal_get_path('module', 'dci_chaos') . '/plugins/styles/dci_teaser/dci_teaser.css', array('preprocess' => TRUE));
  return '<div class="article-teasers">' . $content->content . '</div>';
}
