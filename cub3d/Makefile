NAME = cub3D

CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
RM = rm -rf

MMS_DIR = minilibx_mms_20200219
LMLX = libmlx.dylib
SRCS = ./srcs/main.c \
		./srcs/cub3d.c \
		./srcs/draw.c \
		./srcs/draw_utils.c \
		./srcs/set_texture.c \
		./srcs/sprite.c \
		./srcs/key_loop.c \
		./srcs/key_utils.c \
		./srcs/map_parsing.c \
		./srcs/map_save.c \
		./srcs/save_bmp.c \
		./srcs/utils.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_substr.c \
		./srcs/ft_strchr.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_lstnew.c \
		./srcs/ft_lstadd_back.c \
		./srcs/ft_lstclear.c \
		./srcs/ft_lstsize.c \
		./srcs/ft_lstlast.c \
		./srcs/ft_memset.c \
		./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c

all: $(NAME)

lmx:
	$(MAKE) -C $(MMS_DIR)
	cp $(MMS_DIR)/$(LMLX) .
	
$(NAME): $(SRCS)
	$(MAKE) lmx
	$(CC) $(FLAGS) -I ./include/ $(LMLX) -o $@ $^
	echo "\x1B[32;1m"">>>>> cub3D is successfully made.""\x1B[m"

clean:
	RM $(NAME)

fclean: clean
	RM $(LMLX)
	$(MAKE) -C $(MMS_DIR) clean
	
re: fclean all

bonus: all

.PHONY : all clean fclean re bonus