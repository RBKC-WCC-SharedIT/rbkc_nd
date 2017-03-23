<?php

/**
 * Implementation of hook_drush_command()
 */
function rbkc_nd_drush_command() {
  $items['rbkc-domain-add'] = array(
    'description' => t('Adds a new Domain Access domain'),
    'callback' => 'rbkc_nd_drush_domain_add',
    'arguments' => array(
      'domain' => 'The domain to register (e.g. www.rbkc.gov.uk.nour).',
      'sitename' => 'The name of the site (e.g. Nour).',
      'theme' => 'The theme of the site (e.g. nour)',
    ),
  );

  return $items;
}

function rbkc_nd_drush_domain_add($domain = null, $sitename = null, $domain_theme = null, $uri = null) {
  $errors = array();
  if (!$domain) {
    $errors[] = t('Missing domain and sitename.');
  }
  elseif (!$domain || !$sitename) {
    $errors[] = t('Missing sitename.');
  }
  else {
    // treats the uri arg as theme if we skip theme, so need to test for that too
    if (!$domain || !$sitename || !$domain_theme || !$uri) {
      $errors[] = t('Missing argument.');
    }
  }

  if ($errors) {
    return drush_set_error('rbkc_nd', 'Error: ' . implode('. ', $errors) . ' Syntax: drush rbkc-domain-add <domain> <sitename> <sitetheme> <defaulturi>');
  }

  rbkc_nd_domain_add($domain, $sitename, $domain_theme);
}
