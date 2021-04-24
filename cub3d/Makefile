NAME = cub3d

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

MMS_DIR = minilibx_mms_20200219
OPENGL_DIR = minilibx_opengl_20191021
LMLX = libmlx.dylib libmlxgl.a
SRCS = ./srcs/main.c \
		./srcs/map_parsing.c \
		./srcs/map_parsing_utils.c \
		./srcs/map_save.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_substr.c \
		./srcs/ft_strchr.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_lstnew.c \
		./srcs/ft_lstadd_back.c \
		./srcs/ft_lstclear.c \
		./srcs/ft_lstsize.c \
		./srcs/ft_lstlast.c \
		./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c

all: $(NAME)

$(LMLX):
	$(MAKE) -C $(MMS_DIR)
	$(MAKE) -C $(OPENGL_DIR)

$(NAME): $(LMLX)
	cp $(MMS_DIR)/libmlx.dylib .
	cp $(OPENGL_DIR)/libmlxgl.a .
	$(CC) $(FLAGS) -g -I ./include/ $(LMLX) $(SRCS) -o $(NAME)
	echo "\x1B[32;1m"">>>>> cub3d is successfully made.""\x1B[m"

clean:
	RM $(NAME)

fclean: clean
	RM $(LMLX)
	$(MAKE) -C $(MMS_DIR) clean
	$(MAKE) -C $(OPENGL_DIR) clean

re: fclean all

bonus: all

.PHONY : all clean fclean re bonus