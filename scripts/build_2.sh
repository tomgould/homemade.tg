#!/bin/bash
cd docroot
cp -R ../assets/homemade.tg/ ../docroot/sites

mkdir ../docroot/sites/all/modules/custom
cp -R ../assets/inst_import/ ../docroot/sites/all/modules/custom

mkdir ../docroot/sites/all/modules/features
cp -R ../assets/instagram_item_feature/ ../docroot/sites/all/modules/features
cp -R ../assets/taxonomy_menu_block_feature/ ../docroot/sites/all/modules/features
cp -R ../assets/taxonomy_override_feature/ ../docroot/sites/all/modules/features
cp -R ../assets/pathauto_patterns/ ../docroot/sites/all/modules/features

sudo chmod 2775 ../docroot/
sudo chown -R tgould:www-data ../docroot/
sudo find ../docroot/* -type d -exec chmod 2775 {} \;
sudo find ../docroot/* -type f -exec chmod 664 {} \;
chmod 755 ../docroot/sites/homemade.tg/
chmod 755 ../docroot/sites/homemade.tg/settings.php

mysql -uroot -pPassw0rd -e "DROP DATABASE IF EXISTS homemade_tg;"
mysql -uroot -pPassw0rd -e "CREATE DATABASE homemade_tg;"
mysql -uroot -pPassw0rd homemade_tg < ../assets/databases/database.sql

cd ../docroot/
drush --uri="homemade.tg" dis -y overlay toolbar
drush --uri="homemade.tg" pm-uninstall -y overlay toolbar
drush --uri="homemade.tg" en -y views views_ui admin devel features strongarm taxonomy_menu_block fe_block pathauto
drush --uri="homemade.tg" en -y instagram_item_feature inst_import taxonomy_menu_block_feature taxonomy_override_feature pathauto_patterns
drush --uri="homemade.tg" cc all
drush --uri="homemade.tg" cron
drush --uri="homemade.tg" inst-import-defaults
drush --uri="homemade.tg" vset -y site_frontpage "things-i-like"
drush --uri="homemade.tg" fra -y
drush --uri="homemade.tg" cc all
drush --uri="homemade.tg" inst-import
drush --uri="homemade.tg" cron
drush --uri="homemade.tg" cc all
