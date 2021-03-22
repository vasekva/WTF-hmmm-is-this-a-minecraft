NAME 				=	cub3D

INCLUDES 			=	-I ./includes/ -I ./mlx/
SRCS_DIR			=	./srcs/
LIBFT_DIR			=	./libft/
OBJS_DIR			=	./objs/
LIBRARY				=	./libft/libft.a

SRCS_NAME			=	actions.c			\
						arrange_map.c		\
						bmp.c				\
						check_content.c		\
						check_map.c			\
						colors.c			\
						create_map.c		\
						draw.c				\
						error.c				\
						exit.c				\
						free.c				\
						init_var.c			\
						main.c				\
						motion.c			\
						pix.c				\
						raycasting.c		\
						sprite.c			\
						textures.c			\
						get_next_line.c		\
						exception.c			\
						print_structs.c		\

OBJS_NAME			=	$(SRCS_NAME:.c=.o)

SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS 				=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror
MLX_FLAGS			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all:					$(NAME)

$(NAME): 				$(OBJS)
						@(echo "\033[32m===	CUB3D COMPILATION...	===\033[0m")
						@$(MAKE) -C $(LIBFT_DIR)
						@$(CC) $(LIBRARY) -o $(NAME) $(OBJS) $(MLX_FLAGS)
						@(echo "\033[32m===	CUB3D COMPILATION OK	===\033[0m")

$(OBJS): 				$(SRCS)
						@($(CC) $(INCLUDES) -c $(SRCS))
						@(mv	$(OBJS_NAME) $(OBJS_DIR))
clean:
						@make clean -C ./libft/
						@rm -rf $(OBJS)

fclean: 				clean
						@rm -rf $(NAME)
						@make fclean -C $(LIBFT_DIR)
						@make clean -C ./mlx/
						@echo "\033[34m===	REPERTORY CUB3D CLEANED	===\033[0m"

re:						fclean all

.PHONY:					all clean fclean re
