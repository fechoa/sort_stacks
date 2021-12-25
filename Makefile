# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 15:57:32 by gkelsie           #+#    #+#              #
#    Updated: 2021/11/02 19:30:55 by a1111            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	push_swap.c							stacks.c					atois.c \
			stacks_operations_one.c				stacks_operations_two.c \
			stacks_operations_three.c			sort_three.c				sort_five.c \
			search_position.c					sort_main.c					sort_main_sec.c \
			parser_one.c						parser_two.c
			

OBJ		=	${SRC:.c=.o}
OBJ_D	=	$(patsubst %.c,%.d,$(SRC))

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm

all		:	$(NAME)

$(NAME)	:	${OBJ}

%.o		:	%.c push_swap.h
	${CC} ${FLAGS} -c $< -o $@ -MD


include $(wildcard $(OBJS_D))

clean	:
	${RM} -f ${OBJ} ${OBJ_D}

fclean	:	clean
	${RM} -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus