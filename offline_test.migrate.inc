<?php

/**
 * Implements hook_migrate_api().
 */
function offline_test_migrate_api() {

  $api = array(
    'api' => 2,
    'groups' => array(
      'MongodbMigrate' => array(
        'title' => t('Mongo DB Migrations'),
      ),
    ),
    'migrations' => array(
      'EntityCity' => array(
        'class_name' => 'EntityCityMigration',
        'group_name' => 'MongodbMigrate',
      ),
    ),
  );
  return $api;
}