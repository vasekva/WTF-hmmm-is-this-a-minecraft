NAME 				=	libft.a

OBJS_DIR			=	./objs/

PART2				=	ft_memset.c			\
						ft_putstr.c			\
						ft_strncmp.c		\
						ft_strlen.c			\
						ft_strjoin.c		\
						ft_strdup.c			\
						ft_split_nl.c		\
						ft_strdel.c			\
						ft_atoi.c			\
						ft_calloc.c			\
						ft_strtrim.c		\
						ft_atoi_base.c		\
						ft_itoa_base.c		\
						ft_power.c			\
						ft_isdigit.c		\
						ft_substr.c			\

SRCS				=	$(PART2)

OBJS_NAME			=	$(SRCS:.c=.o)

OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror -I./

all:					$(NAME)

$(NAME):				$(OBJS)
						@echo "\033[32m===	COMPILATION LIBFT...	===\033[0m"
						@ar -rc $(NAME) $(OBJS)
						@ranlib $(NAME)
						@echo "\033[32m===	COMPILATION LIBFT OK	===\033[0m"

$(OBJS):				$(SRCS)
						@($(CC) -c $(SRCS))
						@(mv $(OBJS_NAME) $(OBJS_DIR))

clean:
						@(rm -rf $(OBJS))
						@echo "\033[34m===	LIBFT ./OBJS/ CLEANED	===\033[0m"

fclean:					clean
						@(rm -rf $(NAME))
						@echo "\033[34m===	LIBRARY LIBFT CLEANED	===\033[0m"

re:						fclean all

.PHONY:					clean fclean re all