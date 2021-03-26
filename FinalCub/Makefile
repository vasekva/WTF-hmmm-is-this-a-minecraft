NAME			=	cub3D

INCLUDES		=	-I ./includes/ -I ./mlx/

SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/
LIBFT_DIR		=	./libft/
LIBRARY			=	./libft/libft.a
MLX_DIR			=	./mlx/
MLX_LIB			=	./mlx/libmlx.a

SRCS_NAME		=	main.c					\
					exception.c				\
					get_next_line.c			\
					ft_check_file.c			\
					ft_check_map.c			\
					ft_init_vars02.c		\
					event_handle.c			\
					ft_read_textures.c		\
					ft_start_game.c			\
					raycasting.c			\
					ft_draw.c				\
					ft_draw_walls.c			\
					ft_draw_floor.c			\
					ft_utils_for_draw.c		\
					ft_move_forw_bacw.c		\
					ft_move_side.c			\
					ft_convert_bmp.c		\
					ft_draw_sprites.c		\
					ft_init_map.c			\
					ft_found_and_fill_map.c \
					ft_parse_color.c		\
					ft_utils_for_color.c	\
					ft_def_sprites.c		\
					ft_utils_for_sprites.c	\
					ft_read_screen_size.c	\
					ft_check_params.c		\
					ft_init_cub3d.c			\

OBJS_NAME		= $(SRCS_NAME:.c=.o)

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:				$(NAME)

$(NAME):			$(OBJS)
					@echo	"\033[1m\033[35m===	CUB3D COMPILATION...	===\033[0m"
					@($(MAKE)	-C		$(MLX_DIR))
					@($(MAKE)	-C		$(LIBFT_DIR))
					@($(CC)	$(LIBRARY)	$(MLX_LIB)	-o	$(NAME)	$(OBJS)	$(MLX_FLAGS))
					@echo	"\033[32m===	CUB3D COMPILATION OK	===\033[0m"
					@echo

$(OBJS):			$(SRCS)
					@($(CC)	$(INCLUDES)	-c	$(SRCS))
					@(mv	$(OBJS_NAME)	$(OBJS_DIR))
clean:
					@(make	clean -C	$(LIBFT_DIR))
					@(make	clean -C	$(MLX_DIR))
					@(rm -rf			$(OBJS))
					@echo	"\033[33m===	CUB3D ./OBJS/ CLEANED	===\033[0m"

fclean:				clean
					@(rm	-rf	$(NAME))
					@(rm	-rf	$(LIBRARY))
					@echo	"\033[33m===	LIBRARY LIBFT CLEANED	===\033[0m"
					@echo	"\033[31m\033[1m${RED}===	ВСЕ СОЗДАННЫЕ ФАЙЛЫ УСПЕШНО УДАЛЕНЫ	===\033[0m"
					@echo

re:					fclean all

.PHONY:				all, clean, fclean, re
