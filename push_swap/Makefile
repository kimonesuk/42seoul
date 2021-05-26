NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ./srcs/push_swap.c \

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -I ./include/ -o $@ $^
	echo "\x1B[32;1m"">>>>> push_swap is successfully made <<<<<""\x1B[m"

debug:
	$(CC) $(FLAGS) -I ./include/ -g3 -fsanitize=address $(SRCS) -o $(NAME)
	echo "\x1B[32;1m"">>>>> push_swap is successfully made <<<<<""\x1B[m"

norm:
	norminette ./srcs/*.c ./include/push_swap.h

clean:
	RM $(NAME)

fclean: clean
	RM ./srcs/*.o

re: fclean all

bonus: all

.PHONY : all clean fclean re bonus debug norm