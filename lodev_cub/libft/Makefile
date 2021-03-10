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

SRC = ft_strlen.c ft_isdigit.c ft_substr.c ft_atoi.c ft_isalpha.c ft_strcpy.c

OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rc	$(NAME) $(OBJS)
	ranlib	$(NAME)

clean:
	/bin/$(RM) $(OBJS) $(B_OBJS)

fclean:	clean
	/bin/$(RM) $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re
