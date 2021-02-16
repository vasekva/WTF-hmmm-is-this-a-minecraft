
NAME = Cub3D

SRC =	ft_print_structs.c main.c ft_parse.c \
		ft_write_color.c \
		get_next_line.c \
		init_structs01.c \
		init_structs02.c \
		init_array.c \
		ft_start_game.c \
		event_handle01.c \
		print_DDALine.c \
		ft_utils.c \
		ft_move_player.c \
#		ft_draw_rays.c \
#		ft_draw_cub_from_cubs.c \

INCLUDES = -I ./includes/ -I ./mlx/

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFTDIR = ./libft/

LIBA = ./libft/libft.a

SRCDIR = ./srcs/

OBJDIR = ./objs/

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32m[Cub3D compilation...]"
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBA) ../
	$(CC) $(LIBA) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	@echo "\033[32m[Done!]"
	
$(OBJS): $(SRCS)
	$(CC) $(INCLUDES) -c $(SRCS)
	mv	$(OBJ) $(OBJDIR)

clean:
	make clean -C libft/
	rm -rf $(OBJS)
	rm -rf $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -rf $(NAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY: all, clean, fclean, re
