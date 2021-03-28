NAME 				=	libft.a

INCLUDES			=	-I ./includes/

OBJS_DIR			=	./objs/
SRCS_DIR			=	./srcs/

SRCS_NAME			=	ft_memset.c			\
						ft_strncmp.c		\
						ft_strlen.c			\
						ft_strdup.c			\
						ft_atoi.c			\
						ft_strtrim.c		\
						ft_power.c			\
						ft_isdigit.c		\
						ft_substr.c			\
						ft_strchr.c			\
						ft_strjoin.c		\

OBJS_NAME			=	$(SRCS_NAME:.c=.o)

SRCS				=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC					=	gcc

CFLAGS				=	-Wall -Wextra -Werror

all:					$(NAME)

$(NAME):				$(OBJS)
						@echo "\033[1m\033[35m===	COMPILATION LIBFT...	===\033[0m"
						@ar -rc		$(NAME)			$(OBJS)
						@ranlib		$(NAME)
						@echo "\033[32m===	COMPILATION LIBFT OK	===\033[0m"
						@echo

$(OBJS):				$(SRCS)
						($(CC)		$(INCLUDES) -c	$(SRCS))
						@(mv 		$(OBJS_NAME)	$(OBJS_DIR))

clean:
						@(rm -rf	$(OBJS))
						@echo "\033[33m===	LIBFT ./OBJS/ CLEANED	===\033[0m"

fclean:					clean
						@(rm -rf	$(NAME))
						@echo "\033[33m===	LIBRARY LIBFT CLEANED	===\033[0m"

re:						fclean all

.PHONY:					clean fclean re all