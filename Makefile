# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maearly <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 13:20:49 by maearly           #+#    #+#              #
#    Updated: 2021/01/30 13:20:55 by maearly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	${wildcard *.c}

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all: 		${NAME}

$(NAME): 	${OBJS}
			ar rcs ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean: 	clean
			rm -f ${NAME}

re: 		fclean all

.PHONY	=	clean all fclean re