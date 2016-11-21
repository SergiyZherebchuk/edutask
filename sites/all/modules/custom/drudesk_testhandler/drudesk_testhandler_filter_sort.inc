<?php

class drudesk_testhandler_filter_sort extends views_handler {
  public function query() {
    $fields = "FIELD({$this->table}.{$this->field}, 46)";
  }

  function sort_options() {
    return array(
      'ASC'   =>  t('Sort ascending'),
      'DESC'  =>  t('Sort descending')
    );
  }
}
