This module create a new Domain Access domain and uses Subfolders Domain
module to create domains of the form rbkc.gov.uk/sitename.

To add a domain, run the following drush command:

drush rbkc-domain-add '<domain.path>' '<site name>' --uri=<the site's URL>

E.g.

drush rbkc-domain-add 'www.rbkc.gov.uk.lscb' 'LSCB' --uri=http://www.rbkc.gov.uk

