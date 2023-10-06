# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lganda <lgandari@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 17:33:27 by lganda            #+#    #+#              #
#    Updated: 2023/10/06 18:54:46 by lganda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprint.a

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC	=	ft_printf.c utils.c

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -f

AR	=	ar -cr

all:	$(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.SILENT: all $(NAME) $(OBJ) clean fclean re
.PHONY: all clean fclean re
