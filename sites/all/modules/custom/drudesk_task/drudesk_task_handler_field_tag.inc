<?php

class drudesk_task_handler_field_tag extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    parent::query();
  }

  function render($data) {
    $output = t('Hello!!!');
    return $output;
  }
}
