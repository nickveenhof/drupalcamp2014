<?php
/**
 * @file
 * gent2014_user_register.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function gent2014_user_register_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gent2014_community_anonymous';
  $context->description = 'Add a link (block) to join the "community" on the attendees list';
  $context->tag = 'DrupalCamp Gent 2014';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '/community' => '/community',
        '*/community' => '*/community',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'gent2014_user_register-community_register_link' => array(
          'module' => 'gent2014_user_register',
          'delta' => 'community_register_link',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a link (block) to join the "community" on the attendees list');
  t('DrupalCamp Gent 2014');
  $export['gent2014_community_anonymous'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gent2014_frontpage_anonymous';
  $context->description = 'Context for the Frontpage - Anonymous users';
  $context->tag = 'DrupalCamp Gent 2014';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'intro',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the Frontpage - Anonymous users');
  t('DrupalCamp Gent 2014');
  $export['gent2014_frontpage_anonymous'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gent2014_frontpage_loggedin';
  $context->description = 'Context for the Frontpage - Authenticated users';
  $context->tag = 'DrupalCamp Gent 2014';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
        'content editor' => 'content editor',
        'session organizer' => 'session organizer',
        'sponsor organizer' => 'sponsor organizer',
        'unconfirmed user' => 'unconfirmed user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'intro',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the Frontpage - Authenticated users');
  t('DrupalCamp Gent 2014');
  $export['gent2014_frontpage_loggedin'] = $context;

  return $export;
}
