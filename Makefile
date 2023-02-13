# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:33:27 by vgejno            #+#    #+#              #
#    Updated: 2023/02/12 20:36:03 by vgejno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

SRC = philo.c \
	  parsing.c \

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${FLAGS} ${OBJ} $^ -o ${NAME}

%.o:%.c
	${CC} ${FLAGS} -c $^ -o $@

clean:
	@{RM} ${OBJ}
	
fclean: clean
	@{RM} ${NAME}		

re: fclean all

.PHONY: all clean fclean re