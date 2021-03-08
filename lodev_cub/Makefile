NAME = Cub3D

SRC =	main.c \
		ft_start_game.c \
		event_handle01.c \
		ft_parse.c \
		get_next_line.c \
		ft_parse_screen_size.c \
		ft_parse_path.c \
		ft_parse_color.c \

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