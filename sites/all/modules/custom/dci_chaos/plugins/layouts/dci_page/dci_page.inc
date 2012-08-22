<?php

/**
 * implementation of hook_panels_layouts
 */
// Plugin definition
$plugin = array(
  'title' => t('DCI Page'),
  'category' => t('Full Page'),
  'icon' => 'dci_page.jpg',
  'theme' => 'panels_dci_page',
  'theme arguments' => array('id', 'content'),
  'css' => 'dci_page.css',
  'admin theme' => 'panels_dci_page_admin',
  'admin css' => 'dci_page-admin.css',
  'regions' => array(
    'header' => t('Header'),
    'banner' => t('Banner'),
    'main-before' => t('Before Content'),
    'main' => t('Content'),
    'main-after' => t('After Content'),
    'sidebar-last' => t('Sidebar Last'),
    'footer-1st' => t('Footer First'),
    'footer-2nd' => t('Footer Second'),
    'footer-3rd' => t('Footer Third'),
    'footer-4th' => t('Footer Fourth'),
    'footer-extra-1st' => t('Footer Extra First'),
    'footer-extra-2nd' => t('Footer Extra Second'),
  ),
);
