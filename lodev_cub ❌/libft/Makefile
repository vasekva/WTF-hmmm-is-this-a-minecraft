NAME 				=	libft.a

OBJS_DIR			=	./objs/

PART1 				=	ft_memset.c				\
						ft_bzero.c				\
						ft_memcpy.c				\
						ft_memccpy.c			\
						ft_memmove.c			\
						ft_memchr.c				\
						ft_memcmp.c				\
						ft_strlen.c				\
						ft_isalpha.c			\
						ft_isdigit.c			\
						ft_isalnum.c			\
						ft_isascii.c			\
						ft_isprint.c			\
						ft_toupper.c			\
						ft_tolower.c			\
						ft_strchr.c				\
						ft_strrchr.c			\
						ft_strncmp.c			\
						ft_strlcpy.c			\
						ft_strlcat.c			\
						ft_strnstr.c			\
						ft_atoi.c				\
						ft_calloc.c				\
						ft_strdup.c				\

PART2				=	ft_substr.c				\
						ft_strjoin.c			\
						ft_strtrim.c			\
						ft_split.c				\
						ft_itoa.c				\
						ft_strmapi.c			\
						ft_putchar_fd.c			\
						ft_putstr_fd.c			\
						ft_putendl_fd.c			\
						ft_putnbr_fd.c			\

ADDITIONAL			=	ft_strcmp.c				\
						ft_strjoin_free.c		\
						ft_strdel.c				\
						ft_strndup.c			\
						ft_atoi_base.c			\
						ft_itoa_base.c			\
						convert_base.c			\
						ft_factorial.c			\
						ft_power.c				\
						ft_sqrt.c				\
						ft_swap.c				\
						ft_split_nl.c			\

SRCS				=	$(PART1) $(PART2) $(ADDITIONAL)

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