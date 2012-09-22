<?php

/**
 * HTML header panels wrapper.
 */

// Plugin definition
$plugin = array(
  'title' => t('Drupal Camp Indonesia Sitename'),
  'description' => t('Renders the site name /in colors/.'),
  'render pane' => 'dci_sitename_render_pane',
);

/**
 * Render pane callback.
 */
function theme_dci_sitename_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }
  $pane = $vars['pane'];

  $splitnames = preg_split('/\s+/', $content->content, 3);
  $sitename = $splitnames[0];
  if (isset($splitnames[1])) {
    $sitename .= ' <span class="site-event">' . $splitnames[1] . '</span>';
    if (isset($splitnames[2])) {
      $sitename .= ' <span class="site-regional">' . $splitnames[2] . '</span>';
    }
  }

  if (isset($content->css_id) || isset($content->css_class)) {
    $output = '<span';
    if (isset($content->css_id)) {
      $output .= ' id="' . $content->css_id . '"';
    }
    if (isset($content->css_class)) {
      $output .= ' class="' . $content->css_class . '"';
    }
    $output .= '>' . $sitename . '</span>';
  }
  else {
    return $sitename;
  }
  return $output;
}
