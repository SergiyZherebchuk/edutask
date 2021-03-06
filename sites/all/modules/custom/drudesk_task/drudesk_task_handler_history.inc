<?php

class drudesk_task_handler_history extends views_handler_field {
  function init(&$view, &$options) {
    if (!empty($this->options['link_to_task'])) {
      $this->additional_fields['dd_id'] = 'dd_id';
    }
    parent::init($view, $options);
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_task'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['link_to_task'] = array(
      '#title' => t("Link this field to the task view page"),
      '#description' => t('This task.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_task']),
    );
    parent::options_form($form, $form_state);
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
