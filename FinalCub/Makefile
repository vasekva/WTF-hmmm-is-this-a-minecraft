NAME			=	cub3D

INCLUDES		=	-I ./includes/ -I ./mlx/

SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/
LIBFT_DIR		=	./libft/
LIBRARY			=	./libft/libft.a

SRCS_NAME		=	main.c					\
					exception.c				\
					get_next_line.c			\
					ft_check_file.c			\
					ft_check_map.c			\
					init_vars.c				\
					event_handle.c			\
					exit.c					\
					ft_read_textures.c		\
					ft_start_game.c			\
					raycasting.c			\
					ft_draw.c				\
					ft_draw_walls.c			\
					ft_draw_floor.c			\
					ft_utils_for_draw.c		\
					print_structs.c			\
					ft_move_forw_bacw.c		\
					ft_move_side.c			\
					ft_convert_bmp.c		\
					ft_free_all.c			\
					ft_draw_sprites.c		\
					ft_init_map.c			\
					ft_found_and_fill_map.c \
					ft_parse_color.c		\
					ft_utils_for_color.c	\
					
OBJS_NAME		= $(SRCS_NAME:.c=.o)

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:				$(NAME)
					echo	"\033[32m===	CUB3D COMPILATION...	===\033[0m"
					$(MAKE)	-C	$(LIBFT_DIR)
					$(CC)	$(LIBRARY)	-o	$(NAME)	$(OBJS)	$(MLX_FLAGS)
					echo	"\033[32m===	CUB3D COMPILATION OK	===\033[0m"

$(NAME):			$(OBJS)

$(OBJS):			$(SRCS)
					$(CC)	$(INCLUDES)	-c	$(SRCS)
					mv		$(OBJS_NAME)	$(OBJS_DIR)
clean:
					@echo	"\033[34m===	ВЫПОЛНЯЕТСЯ УДАЛЕНИЕ OBJS ФАЙЛОВ...	===\033[0m"
					make -C ./libft/
					rm -rf	$(OBJS)
					@echo	"\033[34m===			OBJS ФАЙЛЫ УДАЛЕНЫ			===\033[0m"

fclean:				clean
					@echo	"\033[34m===	ВЫПОЛНЯЕТСЯ ЧИСТКА БИБЛЕОТЕК...		===\033[0m"
					rm	-rf	$(NAME)
					make	fclean	-C	$(LIBFT_DIR)
					make	clean	-C	./mlx/
					@echo	"\033[34m===	ВСЕ СОЗДАННЫЕ ФАЙЛЫ УСПЕШНО УДАЛЕНЫ	===\033[0m"

re:					fclean all

.PHONY:				all, clean, fclean, re
