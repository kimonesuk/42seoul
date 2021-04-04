#!/bin/bash

diff -s ./42seoul/ft_server/Dockerfile ./ft_server/Dockerfile > answer.txt
diff -s ./42seoul/ft_server/srcs/config.inc.php ./ft_server/srcs/config.inc.php >> answer.txt
diff -s ./42seoul/ft_server/srcs/wp-config.php ./ft_server/srcs/wp-config.php >> answer.txt
diff -s ./42seoul/ft_server/srcs/default ./ft_server/srcs/default >> answer.txt
diff -s ./42seoul/ft_server/srcs/non_default ./ft_server/srcs/non_default >> answer.txt
diff -s ./42seoul/ft_server/srcs/init.sh ./ft_server/srcs/init.sh >> answer.txt
diff -s ./42seoul/ft_server/srcs/run.sh ./ft_server/srcs/run.sh >> answer.txt
