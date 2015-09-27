<?php
/**
 * @file
 * taxonomy_menu_block_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function taxonomy_menu_block_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
