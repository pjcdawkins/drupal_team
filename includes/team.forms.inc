<?php
/**
 * @file
 * Form builder functions for the Team module.
 */

/**
 * The team create/edit form.
 */
function team_form($form, &$form_state, Team $team = NULL, $op = 'edit', $entity_type = NULL) {
  form_load_include($form_state, 'inc', 'team', 'includes/team.forms');

  if ($team === NULL) {
    $team = entity_create('team', array('type' => 'team'));
  }

  $form_state['team'] = $team;

  if ($op == 'clone') {
    // Only label is provided for cloned entities.
    $team->label .= ' (cloned)';
    $team->type = $entity_type . '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => isset($team->label) ? $team->label : '',
  );
  // Machine-readable team name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($team->name) ? $team->name : '',
    '#machine_name' => array(
      'exists' => 'team_load_by_name',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this team. It must only contain lowercase letters, numbers, and underscores.'),
  );

  field_attach_form('team', $team, $form, $form_state);

  $form['actions'] = array('#type' => 'actions', '#weight' => 100);
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save team'),
  );

  if (isset($_GET['destination'])) {
    $cancel_path = $_GET['destination'];
  }
  elseif (!empty($team->team_id)) {
    $cancel_path = 'team/' . $team->team_id;
  }
  elseif (!empty($team->uid)) {
    $cancel_path = 'user/' . $team->uid . '/teams';
  }
  if (isset($cancel_path)) {
    $form['actions']['cancel'] = array(
      '#markup' => l(t('Cancel'), $cancel_path),
    );
  }

  return $form;
}

/**
 * Validate callback for the team create/edit form.
 *
 * @see team_form()
 */
function team_form_validate(&$form, &$form_state) {
  field_attach_form_validate('team', $form_state['team'], $form, $form_state);
}

/**
 * Submit callback for the team create/edit form.
 *
 * @see team_form()
 */
function team_form_submit(&$form, &$form_state) {
  $team = $form_state['team'];
  $team->name = $form_state['values']['name'];
  $team->label = $form_state['values']['label'];
  field_attach_submit('team', $team, $form, $form_state);
  $team->save();

  drupal_set_message(t('The team %label was saved.', array('%label' => $team->label)));

  $form_state['redirect'] = 'team/' . $team->team_id;
}
