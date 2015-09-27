<?php

/**
 * @file
 *    Drsh commands for the import jobs
 */

/**
 * Implements hook_drush_command().
 */
function inst_import_drush_command() {
  $items['inst-import']          = array(
    'description' => dt('Import instagram items'),
    'aliases'     => array('ii-import', 'iii'),
  );
  $items['inst-import-defaults'] = array(
    'description' => dt('Set up some defaults'),
  );
  return $items;
}

/**
 * imports content
 */
function drush_inst_import($importer_function = FALSE, $remote_type = FALSE) {
  inst_import_import_content($importer_function, $remote_type);
}

/**
 * Purges all content
 */
function drush_inst_import_defaults() {
  taxonomy_term_save((object) array(
        'name' => 'Cats',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Dogs',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Cheese',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Monkeys',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Beer',
        'vid'  => '1',
  ));
}
