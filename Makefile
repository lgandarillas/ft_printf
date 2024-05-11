# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 17:33:27 by lganda            #+#    #+#              #
#    Updated: 2024/05/11 19:33:39 by lgandari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror
DFLAGS	=	-g3 #-fsanitize=address

SRC	=	ft_printf.c putnbr.c utils.c

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -f

AR	=	ar -cr

all:	$(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

debug: CFLAGS += $(DFLAGS)
debug: all

.SILENT: all $(NAME) $(OBJ) clean fclean
.PHONY: all clean fclean re
