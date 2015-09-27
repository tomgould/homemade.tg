#!/bin/bash
sudo rm -rf docroot
mkdir docroot
cd docroot
drush make ../scripts/homemade.tg.make -y

