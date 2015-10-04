<?php
/**
 * @file
 * Field and instance definitions for the Team module.
 */

/**
 * Required field bases.
 *
 * @see field_create_field()
 *
 * @internal
 *
 * @return array
 *   An array of field definitions.
 */
function team_required_field_bases() {
  $field_bases = array();

  // Exported field_base: 'team_users'
  $field_bases['team_users'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'team_users',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'name',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'user' => 'user',
        ),
      ),
      'target_type' => 'user',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}

/**
 * Required instances.
 *
 * @see field_create_instance()
 *
 * @internal
 *
 * @return array
 *   An array of field instance definitions.
 */
function team_required_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'team-team-team_users'
  $field_instances['team-team-team_users'] = array(
    'bundle' => 'team',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'team',
    'field_name' => 'team_users',
    'label' => t('Users'),
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(),
      ),
      'type' => 'inline_entity_form',
      'weight' => 1,
    ),
  );

  return $field_instances;
}
