FROM	debian:buster 

LABEL	maintainer="okim@student.42seoul.kr"

RUN	apt-get update && apt-get install -y \
	vim \
	nginx \
	openssl \
	php7.3-fpm \
	mariadb-server \
	php-mysql \
	php-mbstring \
	php-xml

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp
COPY	./srcs/phpmyadmin.tar.gz ./tmp
COPY	./srcs/wordpress.tar.gz ./tmp

EXPOSE	80 443

CMD 	bash run.sh
