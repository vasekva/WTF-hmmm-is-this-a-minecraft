
NAME = cub3D.a

MLXLIB= ./mlx/libmlx.a

SRCS = main.c \
		./libft/ft_isdigit.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		ft_abs.c \
		key_press.c \
		create_trgb.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

%.o : %.с
	$(СС) $(CFLAGS) -Imlx $< -o $@ 

$(NAME): $(OBJS)
	make -C ./mlx
	cp $(MLXLIB) $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C ./mlx
	rm -rf ./get_next_line/*.o
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./mlx
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re