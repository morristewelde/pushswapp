# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 22:39:33 by mtewelde          #+#    #+#              #
#    Updated: 2024/10/13 23:46:20 by mtewelde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC			=	push_swap.c src/is_sorted.c src/sort_five.c src/sort_x.c\
				src/push.c src/rotate.c src/rrotate.c src/swap.c src/initialize.c\
				src/valid_args.c src/lst_utils.c src/ft_atol.c src/ft_split.c
				

CFLAGS		=	-Wall -Werror -Wextra

OBJS		=	${SRC:.c=.o}

NAME		=	push_swap

CC			=	cc

RM			=	rm -rf

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
