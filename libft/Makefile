# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 19:47:14 by jberegon          #+#    #+#              #
#    Updated: 2020/11/10 20:07:32 by jberegon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcat.c 		\
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c 		\
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strdup.c 		\
	  ft_calloc.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_substr.c 		\
	  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c		\
	  ft_putstr.c ft_putendl.c ft_putnbr_fd.c ft_split.c ft_lstnew.c  \
	  ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c			\
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcpy.c

OBJS = $(SRC:.c=.o)

BONUS = ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstlast.c ft_lstiter.c		\
		ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c
B_OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rc	$(NAME) $(OBJS)
	ranlib	$(NAME)

bonus:	$(OBJS) $(B_OBJS)
		ar -rc $(NAME) $(OBJS) $(B_OBJS)
		ranlib $(NAME)

clean:
	/bin/$(RM) $(OBJS) $(B_OBJS)

fclean:	clean
	/bin/$(RM) $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re, bonus
