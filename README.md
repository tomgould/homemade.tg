homemade.tg
=============

A demo that builds a drupal sites with Drush Make and then configures the site
with some custom modules and features to downloads data from the Instagram API
and presents it (in a very basic way) via Drupal 7.

The custom modules, features and site directory are contained within the ./assets
directory and are copied over to the correct locations when running the RUNME.sh

The assets directory also contains a database made by going through the basic
install.php steps to set the username and password, nothing more.

The inst_import module uses the Tags vocab and requests posts from Instagram
that have been tagged with said tags.

As this is just a demo there is no UI for the module, there are constants that
I would have made in to variables, changeable via a UI.

Currently there is a hook cron function that imports the content and a Drush
command to do the same thing. Personally I would have the cron import as an
option in UI and then call the drush command from a crontab so the Drupal cron
could still be called without importing content.

The import job is recursive so as to use the paging supplied by the API, the
number iterations and the number of posts per page are set as the constants.

To make the inst_import module I used code I had previously written to import
nodes from Drupal 6 to 7 without using the Migrate module.
https://github.com/tomgould/tom-gould.co.uk/tree/master/sites/tom-gould.co.uk/modules/json_import

I spent more than 3 hours on this as I saw it as an opportunity to make something
that could be built completely from scratch using Drush Make as I was interested
in doing this personally.


More Ideas
------------
0. A profanity filter on the tags to try to mitigate some things
0. A drush command with parameters for Tag, Number of items, Iterations, etc
0. Add a vocab and case for Instagram user feeds
0. When there are lots of Tags there can be allot of posts so you could merge the arrays of posts and then set a max number of posts per run or iteration and then only download so many posts, randomly selected per run
0. Make the UI
0. Make the front end nice


Prerequisites
------------

You will need:

0. Linux machine set up for Drupal development (Apache, MySQL, PHP) with internet access and root access
0. Drush
0. This repo checked out locally to a writable location
0. A local site set up called homemade.tg mapped to ./docroot (Example Vhosts config is below)
0. A database user called "root" identified by password "Passw0rd". You could edit the ./scripts/build_2.sh, lines 20, 21, 22 to match your current user.


homemade.tg.conf:

    <VirtualHost *:80>
        ServerName homemade.tg
        DocumentRoot /home/tgould/www/homemade.tg/docroot

        <Directory /home/tgould/www/homemade.tg/docroot>
            Options +Indexes +FollowSymLinks +ExecCGI
            AllowOverride All
            Order allow,deny
            Allow from all
            Require all granted
        </Directory>

        ErrorLog ${APACHE_LOG_DIR}/error.log
        # Possible values include: debug, info, notice, warn, error, crit,
        # alert, emerg.
        LogLevel warn
        CustomLog ${APACHE_LOG_DIR}/access.log combined
    </VirtualHost>


Building the site
-------------

When you have everything listed above open a console and cd to the root of
this repository eg:

    $ cd ~/www/homemade.tg

In the root of the repo is a file called RUNME.sh, run it from the CLI

    $ sh RUNME.sh

The site will now build and configure the default tags and complete one run of
content gathering from Instagram.

Subsequent cron runs will gather more data or you can do this manually with drush

    $ cd docroot/
    $ drush --uri="homemade.tg" inst-import
    $ drush --uri="homemade.tg" cc all

The admin user and password for the site are: admin:Passw0rd


My Local Setup
------------

In case you have issues here is my local config


    $ php -v
      PHP 5.5.9-1ubuntu4.6 (cli) (built: Feb 13 2015 19:17:11)
      Copyright (c) 1997-2014 The PHP Group
      Zend Engine v2.5.0, Copyright (c) 1998-2014 Zend Technologies
      with Zend OPcache v7.0.3, Copyright (c) 1999-2014, by Zend Technologies
      with Xdebug v2.2.3, Copyright (c) 2002-2013, by Derick Rethans


    $ apache2 -v
      Server version: Apache/2.4.7 (Ubuntu)
      Server built:   Jul 22 2014 14:36:38


    $ mysql -uroot -pPassw0rd
      Welcome to the MySQL monitor.  Commands end with ; or \g.
      Your MySQL connection id is 91
      Server version: 5.5.41-0ubuntu0.14.04.1 (Ubuntu)

    $ php -m
      [PHP Modules]
      bcmath
      bz2
      calendar
      Core
      ctype
      date
      dba
      dom
      ereg
      exif
      fileinfo
      filter
      ftp
      gd
      gettext
      hash
      iconv
      json
      libxml
      mbstring
      mhash
      mysql
      mysqli
      openssl
      pcntl
      pcre
      PDO
      pdo_mysql
      Phar
      posix
      Reflection
      session
      shmop
      SimpleXML
      soap
      sockets
      SPL
      standard
      sysvmsg
      sysvsem
      sysvshm
      tokenizer
      wddx
      xdebug
      xml
      xmlreader
      xmlwriter
      Zend OPcache
      zip
      zlib

      [Zend Modules]
      Xdebug
      Zend OPcache


    $ apachectl -M
      Loaded Modules:
       core_module (static)
       so_module (static)
       watchdog_module (static)
       http_module (static)
       log_config_module (static)
       logio_module (static)
       version_module (static)
       unixd_module (static)
       access_compat_module (shared)
       alias_module (shared)
       auth_basic_module (shared)
       authn_core_module (shared)
       authn_file_module (shared)
       authz_core_module (shared)
       authz_host_module (shared)
       authz_user_module (shared)
       autoindex_module (shared)
       deflate_module (shared)
       dir_module (shared)
       env_module (shared)
       filter_module (shared)
       mime_module (shared)
       mpm_prefork_module (shared)
       negotiation_module (shared)
       php5_module (shared)
       rewrite_module (shared)
       setenvif_module (shared)
       status_module (shared)

