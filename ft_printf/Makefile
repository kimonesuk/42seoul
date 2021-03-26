# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okim <okim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 00:23:55 by okim              #+#    #+#              #
#    Updated: 2021/03/26 19:11:10 by okim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

SRCS = ft_printf.c \
		format_parser.c \
		print_format.c \
		base_print.c \
		int_print.c \
		int_len_chk.c \
		str_print.c \
		etc_print.c \
		utilities.c \
		conv_base.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_isdigit.c \
		ft_strlen.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re