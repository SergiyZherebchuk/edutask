<?php

/*
 * Implements hook_views_data()
 */

function drudesk_testhandler_views_data()
{
  $data['node']['testhandler'] = array(
    'group'   =>  t('Custom'),
    'title'   =>  t('Test handler'),
    'help'    =>  'Test handler from edutask.loc',
    'filter'  =>  array(
      'handler'   =>  'drudesk_testhandler_handler_fieldhandl',
    ),
    'sort'    =>  array(
      'handler'   =>  'drudesk_testhandler_filter_sort'
    )
  );

  return $data;
}
