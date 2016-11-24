<?php

/*
 * Implements form
 */
function drudesk_fields_form($form, &$form_state)
{
	if(isset($form_state['values'])) {
		$step = $form_state['step'] + 1;
	} else {
		$step = 0;
	}

	$form_state['step'] = $step;
	$allstep = get_multi_form();
	$current_form = $allstep[$step];

	return $form;
}

function get_multi_form() {

	$form[0]['name'] = array(
		'#type' =>  'textfield',
		'#title'  =>  t('Name'),
		'#description'  =>  'Enter your name',
		'#size' =>  20,
		'#maxlength'  =>  32,
		'#default_value'  =>  !empty($form_state['values']['name']) ? $form_state['values']['name'] : ''
	);

	$form[0]['age'] = array(
		'#type' =>  'textfield',
		'#title'  =>  t('Age'),
		'#description'  =>  'Enter your age',
		'#default_value'  =>  !empty($form_state['values']['name']) ? $form_state['values']['name'] : ''
	);

	$form[0]['submit'] = array(
		'#type' =>  'submit',
		'#value'  =>  'Next >>'
	);

	$form[1]['tag'] = array(
		'#type' =>  'textfield',
		'#title'  =>  t('Tag'),
		'#required' =>  TRUE,
		'#default_value'  =>  !empty($form_state['values']['Tag']) ? $form_state['values']['tag'] : ''
	);

	$form[1]['submit'] = array(
		'#type' =>  'submit',
		'#value'  =>  'Next >>'
	);

	$form[2]['history'] = array(
		'#type' =>  'textarea',
		'#title'  =>  t('History'),
		'#required' =>  TRUE,
		'#default_value'  =>  !empty($form_state['values']['history']) ? $form_state['values']['history'] : ''
	);

	$form[2]['submit'] = array(
		'#type' =>  'submit',
		'#value'  =>  'Submit'
	);

	return $form;
}

function multi_form_submit($form, &$form_state) {
	$form_state['values'][$form_state['step']] == $form_state['values'];
	if($form_state['step'] + 1 != count(get_multi_form())) {
		$form_state['rebuild'] = TRUE;
	} else {

		$query = db_insert('drudesk_table')
			->fields(array(
				'name'  =>  $form_state['values']['name'],
				'age' =>  $form_state['values']['age'],
				'tag' =>  $form_state['values']['tag'],
				'history' =>  $form_state['values']['history']
			))
			->execute();

		if($query > 0) {
			drupal_set_message(t("Data successfully added"));
		} else {
			drupal_set_message(t("Data unfortunately not added."), 'error');
		}

	}
}
