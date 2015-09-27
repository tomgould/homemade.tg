<?php
/**
 * @file
 * taxonomy_menu_block_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function taxonomy_menu_block_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__tags';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_block_1';
  $strongarm->value = array(
    'delta' => 1,
    'admin_title' => '',
    'vid' => '1',
    'parent' => '0',
    'parent_fixed' => '1',
    'parent_dynamic' => '1',
    'depth' => '1',
    'home_link' => 1,
    'nodes' => 1,
    'nodes_aggregation' => 0,
    'hide_empty' => 0,
    'ctype' => array(
      0 => 'instagram_item',
    ),
  );
  $export['taxonomy_menu_block_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_menu_block_ids';
  $strongarm->value = array(
    0 => 1,
  );
  $export['taxonomy_menu_block_ids'] = $strongarm;

  return $export;
}
