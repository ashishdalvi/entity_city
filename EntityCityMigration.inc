<?php

class EntityCityMigration extends Migration {

  public function __construct($arguments) {

    parent::__construct($arguments);
    $url = 'http://127.0.0.1/personal/offline_d7test/cities.json';

    $fields = array(
      '_id' => 'Unique ID',
      'city' => 'City ID',
      'loc' => 'Location',
      'pop' => 'POP',
      'state' => 'State of the city',
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        '_id' => array(
          'type' => 'varchar',
          'length' => 255,
          'description' => 'Entity ID',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->source = new MigrateSourceJSON($url, '_id', $fields);

    /// Set up our destination - term of type voyages
    $this->destination = new MigrateDestinationEntityAPI('entity_city', 'city_entity_bundle');
    $this->addFieldMapping('title', 'city');
    $this->addFieldMapping('location', 'loc');
    $this->addFieldMapping('pop', 'pop');
    $this->addFieldMapping('state', 'state');
    $this->addFieldMapping('id', '_id')
      ->issueGroup(t('MongodbMigrate'));
  }

  public function prepareRow($row) {
    watchdog('prepare_row', '<pre>' . print_r($row, TRUE) . '</pre>');
    dsm($row);
  }
}

