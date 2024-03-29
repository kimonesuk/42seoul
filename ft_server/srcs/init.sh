#!/bin/bash

#nginx, ssl, redirection, autoindex, php-fpm connection settings
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Okim/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
cp ./tmp/default ./etc/nginx/sites-available/

#mysql, phpmyadmin settings
wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz -P ./tmp/
tar -xf ./tmp/phpMyAdmin-5.1.0-all-languages.tar.gz -C ./tmp/
mv ./tmp/phpMyAdmin-5.1.0-all-languages ./tmp/phpmyadmin
mv ./tmp/phpmyadmin ./var/www/html/
cp ./tmp/config.inc.php ./var/www/html/phpmyadmin/
service php7.3-fpm start # before sql, php-fpm start
service mysql start # mysql start
mysql < var/www/html/phpmyadmin/sql/create_tables.sql
mysql -e "create database if not exists wordpress"
mysql -e "create user 'okim'@'localhost' identified by 'okims'"
mysql -e "grant all privileges on wordpress.* to 'okim'@'localhost' with grant option"
service mysql reload # mysql reload

#wordpress settings
wget https://wordpress.org/latest.tar.gz -P ./tmp/
tar -xf ./tmp/latest.tar.gz -C ./tmp/
mv ./tmp/wordpress ./var/www/html/
cp ./tmp/wp-config.php ./var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

service php7.3-fpm reload # php reload
