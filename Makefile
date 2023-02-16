# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:33:27 by vgejno            #+#    #+#              #
#    Updated: 2023/02/15 18:11:50 by vgejno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

SRC = philo.c \
	  parsing.c \
	  error.c \
	  time.c \
	  init.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${FLAGS} ${OBJ} -o ${NAME}
	@echo "\033[0;32m"".philo executable created""\033[0m"

%.o:%.c
	@${CC} ${FLAGS} -c $^ -o $@

clean:
	@${RM} ${OBJ}
	@echo "\033[0;31m""*.o files deleted""\033[0m"
	
fclean: clean
	@${RM} ${NAME}
	@echo "\033[0;31m"".philo executable deleted""\033[0m"	

re: fclean all

.PHONY: all clean fclean re