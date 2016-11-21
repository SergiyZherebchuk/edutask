<?php

function drudesk_table_views_data_alter(&$data) {
  $data['article']['all_tags']['relationship'] = array(
    'title'       =>  t('Relationship by tags'),
    'label'       =>  t('Relationship by tags'),
    'help'        =>  t('My relationship'),
    'handler'     =>  'table_handler_relationship_all_tags',
    'base'        =>  'tags',
    'base field'  =>  'tags',
    'relationships table' =>  'drupal_table',
    'relationships field' =>  'drupal_table.tags'
  );
}
