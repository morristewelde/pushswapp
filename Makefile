# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtewelde <mtewelde@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 23:48:08 by mtewelde          #+#    #+#              #
#    Updated: 2024/10/23 00:47:47 by mtewelde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
NAME_BONUS  = checker

SRC         = main.c src/sort_five.c src/sort_big.c\
              src/3push.c src/2rotate.c src/4reverse_rotate.c src/1swap.c src/ft_create_stack.c\
              src/check_av.c src/utils_stack.c src/utils.c src/ft_split.c

SRC_BONUS   = src_bonus/bonus.c src_bonus/3push.c src_bonus/2rotate.c src_bonus/4reverse_rotate.c src_bonus/1swap.c\
                src/sort_five.c src/sort_big.c src/ft_create_stack.c\
                src/check_av.c src/utils_stack.c src/utils.c src/ft_split.c\
                gnl/get_next_line.c gnl/get_next_line_utils.c

CFLAGS      = -Wall -Werror -Wextra -g

OBJS        = ${SRC:.c=.o}
OBJS_BONUS  = ${SRC_BONUS:.c=.o}

CC          = cc
RM          = rm -rf

all: ${NAME}

bonus: ${NAME_BONUS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all
