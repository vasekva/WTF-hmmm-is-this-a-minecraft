
NAME = Cub3D

SRC = main.c init_var_01.c init_var_02.c get_map.c event_handle.c \
	event_handle_01.c ray_len.c raycaster.c color.c draw.c check_errors.c \
	fun_error.c

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
