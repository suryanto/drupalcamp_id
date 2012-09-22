<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('DCI Mini Header'),
  'category' => t('Header'),
  'icon' => 'dci_mini_header.jpg',
  'theme' => 'panels_dci_mini_header',
  'theme arguments' => array('id', 'content'),
  'css' => 'dci_mini_header.css',
  'regions' => array(
    'logo' => t('Site info'),
    'menu' => t('Primary menu'),
  ),
);
