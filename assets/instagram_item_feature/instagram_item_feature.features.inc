<?php
/**
 * @file
 * instagram_item_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function instagram_item_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function instagram_item_feature_node_info() {
  $items = array(
    'instagram_item' => array(
      'name' => t('Instagram Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
