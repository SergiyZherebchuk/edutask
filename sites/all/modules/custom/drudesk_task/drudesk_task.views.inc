<?php

/**
 * Implements hook_views_data()
 */
function drudesk_task_views_data() {
  $data = array();

  $data['drudesk_table']['table']['group'] = t('Drudesk');

  $data['drudesk_table']['table']['base'] = array(
    'field' => 'dd_id',
    'title' => t('DD Table'),
    'help' => t('Table from the DDT'),
  );

  $data['drudesk_table']['table']['join'] = array(
    'node' => array(
      'left_field' => 'dd_id',
      'field' => 'dd_id',
    ),
  );

  $data['drudesk_table']['dd_id'] = array(
    'title' => t('Id'),
    'help' => t('Id by DDT'),
    'field' => array(
      'handler' => 'drudesk_task_handler_history',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'drudesk_task_handler_argument_dd_id',
    ),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('Default label'),
      'title' => t('Title by relationships'),
      'help' => t('More information'),
    ),
  );

  $data['drudesk_table']['name'] = array(
    'title' => t('Name'),
    'help' => t('Name by Drudesk table'),
    'field' => array(
      'handler' => 'drudesk_task_handler_history',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['drudesk_table']['age'] = array(
    'title' => t('Age'),
    'help' => t('Age my drudesk table'),
    'field' => array(
      'handler' => 'drudesk_task_handler_history',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['drudesk_table']['tag'] = array(
    'title' => t('Tag'),
    'help' => t('Tag by drudesk table'),
    'field' => array(
      'handler' => 'drudesk_task_handler_field_tag',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'drudesk_task_handler_filter_tag',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['drudesk_table']['history'] = array(
    'title' => t('History'),
    'help' => t('History by DDT'),
    'field' => array(
      'handler' => 'drudesk_task_handler_history',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}
