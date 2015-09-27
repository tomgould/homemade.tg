<?php

/**
 * @file
 * taxonomy_override_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function taxonomy_override_feature_views_default_views() {
  $export = array();

  $view              = new view();
  $view->name        = 'taxonomy_override';
  $view->description = '';
  $view->tag         = 'default';
  $view->base_table  = 'node';
  $view->human_name  = 'Taxonomy Override';
  $view->core        = 7;
  $view->api_version = '3.0';
  $view->disabled    = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler                                                                                = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title']                                             = 'Things I like';
  $handler->display->display_options['use_more_always']                                   = FALSE;
  $handler->display->display_options['access']['type']                                    = 'perm';
  $handler->display->display_options['cache']['type']                                     = 'none';
  $handler->display->display_options['query']['type']                                     = 'views_query';
  $handler->display->display_options['exposed_form']['type']                              = 'basic';
  $handler->display->display_options['pager']['type']                                     = 'full';
  $handler->display->display_options['pager']['options']['items_per_page']                = '32';
  $handler->display->display_options['pager']['options']['offset']                        = '0';
  $handler->display->display_options['pager']['options']['id']                            = '0';
  $handler->display->display_options['pager']['options']['quantity']                      = '9';
  $handler->display->display_options['style_plugin']                                      = 'grid';
  $handler->display->display_options['row_plugin']                                        = 'fields';
  /* Field: Content: inst_image */
  $handler->display->display_options['fields']['field_inst_image']['id']                  = 'field_inst_image';
  $handler->display->display_options['fields']['field_inst_image']['table']               = 'field_data_field_inst_image';
  $handler->display->display_options['fields']['field_inst_image']['field']               = 'field_inst_image';
  $handler->display->display_options['fields']['field_inst_image']['label']               = '';
  $handler->display->display_options['fields']['field_inst_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_inst_image']['click_sort_column']   = 'fid';
  $handler->display->display_options['fields']['field_inst_image']['settings']            = array(
    'image_style' => 'medium',
    'image_link'  => 'content',
  );
  /* Sort criterion: Content: inst_created_time (field_inst_created_time) */
  $handler->display->display_options['sorts']['field_inst_created_time_value']['id']      = 'field_inst_created_time_value';
  $handler->display->display_options['sorts']['field_inst_created_time_value']['table']   = 'field_data_field_inst_created_time';
  $handler->display->display_options['sorts']['field_inst_created_time_value']['field']   = 'field_inst_created_time_value';
  $handler->display->display_options['sorts']['field_inst_created_time_value']['order']   = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id']                           = 'status';
  $handler->display->display_options['filters']['status']['table']                        = 'node';
  $handler->display->display_options['filters']['status']['field']                        = 'status';
  $handler->display->display_options['filters']['status']['value']                        = 1;
  $handler->display->display_options['filters']['status']['group']                        = 1;
  $handler->display->display_options['filters']['status']['expose']['operator']           = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id']                             = 'type';
  $handler->display->display_options['filters']['type']['table']                          = 'node';
  $handler->display->display_options['filters']['type']['field']                          = 'type';
  $handler->display->display_options['filters']['type']['value']                          = array(
    'instagram_item' => 'instagram_item',
  );

  /* Display: Page */
  $handler                                                                                    = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments']                                 = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id']                                = 'tid';
  $handler->display->display_options['arguments']['tid']['table']                             = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field']                             = 'tid';
  $handler->display->display_options['arguments']['tid']['title_enable']                      = TRUE;
  $handler->display->display_options['arguments']['tid']['title']                             = '%1';
  $handler->display->display_options['arguments']['tid']['default_argument_type']             = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records']      = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format']                 = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path']                                                  = 'taxonomy/term/%';

  /* Display: HomePage */
  $handler                                   = $view->new_display('page', 'HomePage', 'page_1');
  $handler->display->display_options['path'] = 'things-i-like';
  $export['taxonomy_override']               = $view;

  return $export;
}
