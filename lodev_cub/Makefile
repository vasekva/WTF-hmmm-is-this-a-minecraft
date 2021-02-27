NAME = Cub3D

SRC =	main.c \
		ft_start_game.c \
		event_handle01.c \

INCLUDES = -I ./includes/ -I ./mlx/

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

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
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	@echo "\033[32m[Done!]"
	
$(OBJS): $(SRCS)
	$(CC) $(INCLUDES) -c $(SRCS)
	mv	$(OBJ) $(OBJDIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
