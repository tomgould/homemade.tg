<?php
/**
 * @file
 * taxonomy_menu_block_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function taxonomy_menu_block_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['taxonomy_menu_block-1'] = array(
    'cache' => 4,
    'custom' => '0',
    'delta' => '1',
    'module' => 'taxonomy_menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => '1',
        'theme' => 'bartik',
        'weight' => '0',
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
