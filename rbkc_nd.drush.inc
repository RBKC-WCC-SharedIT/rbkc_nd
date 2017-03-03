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
    ),
  );
  
  return $items;
}

function rbkc_nd_drush_domain_add($domain = null, $sitename = null) {
  $errors = array();
  if (!$domain) {
    $errors[] = t('Missing domain and sitename.');
  }
  else {
    if (!$domain || !$sitename) {
      $errors[] = t('Missing sitename.');
    }
  }
  
  if ($errors) {
    return drush_set_error('rbkc_nd', 'Error: ' . implode('. ', $errors) . ' Syntax: drush rbkc-domain-add <domain> <sitename>');
  }
  
  rbkc_nd_domain_add($domain, $sitename);
}
