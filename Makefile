# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 18:56:11 by saazcon-          #+#    #+#              #
#    Updated: 2023/05/16 00:48:03 by saazcon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= push_swap.c \
			split.c \
			utils.c \
			push_node.c \
			push_basic_rules.c \
			push_double_rules.c \
			push_checks.c \
			push_error.c \
			push_math.c \
			push_order_3.c \
			push_order_5.c \
			push_order_100_pt1.c \
			push_order_100_pt2.c \
			push_order_500.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror
RM		= rm -f

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re