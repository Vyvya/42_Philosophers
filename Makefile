# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:33:27 by vgejno            #+#    #+#              #
#    Updated: 2023/02/21 16:04:00 by vgejno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SFLAGS =  -fsanitize=thread
PTHLIB =  -lpthread
RM = rm -f

SRC = philo.c \
	  parsing.c \
	  error.c \
	  time.c \
	  init.c \
	  simulation.c \
	  meal.c \
	  monitoring.c \
	  print.c \
	  utils.c
	  

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${FLAGS} ${SFLAGS} ${PTHLIB} ${OBJ} -o ${NAME}
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