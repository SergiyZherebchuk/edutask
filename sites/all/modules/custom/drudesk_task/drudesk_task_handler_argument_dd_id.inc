<?php

class drudesk_task_handler_argument_dd_id extends views_handler_argument_numeric {
  function title_query() {
    $titles = array();
    $result = db_select('drudesk_table', 'cp')
      ->fields('cp', array('title'))
      ->condition('cp.dd_id', $this->value)
      ->execute();
    foreach ($result as $product) {
      $titles[] = check_plain($product->title);
    }
    return $titles;
  }
}
