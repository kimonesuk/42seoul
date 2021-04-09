FROM	debian:buster

LABEL	maintainer="okim@student.42seoul.kr"

RUN	apt-get update && apt-get install -y \
	vim \
	wget \
	nginx \
	openssl \
	php7.3-fpm \
	mariadb-server \
	php-mysql \
	php-mbstring \
	php-xml

COPY	./srcs/init.sh ./
COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/non_default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

RUN	bash init.sh

CMD 	bash run.sh
