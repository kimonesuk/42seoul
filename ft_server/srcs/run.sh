#!/bin/bash

#Autoindex
echo "Autoindex [ on / off ]"
read Auto
if [ $Auto == "off" ]
then
	cp ./tmp/non_default ./etc/nginx/sites-available/default
else
	cp ./tmp/default ./etc/nginx/sites-available/
fi

#Run server
service php7.3-fpm start
service mysql start
service nginx start

bash
