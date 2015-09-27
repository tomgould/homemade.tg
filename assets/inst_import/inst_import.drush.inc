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
function drush_inst_import() {
  inst_import_import_content();
}

/**
 * Sets some defaults
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
        'name' => 'Beer',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Monkeys',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Puppies',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Kittens',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'DeepDream',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Food',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Holbox',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Mexico',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Linux',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Drupal',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Cars',
        'vid'  => '1',
  ));
  taxonomy_term_save((object) array(
        'name' => 'Bikes',
        'vid'  => '1',
  ));
}
