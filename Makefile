# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:33:27 by vgejno            #+#    #+#              #
#    Updated: 2023/03/02 15:13:28 by vgejno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
# SFLAGS = -g -fsanitize=thread
PTHLIB =  -lpthread
RM = rm -f

SRC = philo.c \
	  parse.c \
	  mutex.c \
	  join.c \
	  error.c \
	  time.c \
	  init.c \
	  simu.c \
	  eat.c \
	  think.c \
	  sleep.c \
	  monitor.c \
	  print.c \
	  utils.c
	  

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	@# @${CC} ${CFLAGS} ${SFLAGS} ${PTHLIB} ${OBJ} -o ${NAME}
	@ ${CC} ${CFLAGS} ${PTHLIB} ${OBJ} -o ${NAME}
	@echo "\033[38;2;14;195;6m"".philo executable created""\033[0m"

%.o:%.c
	@${CC} ${CFLAGS} -c $^ -o $@

clean:
	@${RM} ${OBJ}
	@echo "\033[38;2;0;80;255m""*.o files deleted""\033[0m"
	
fclean: clean
	@${RM} ${NAME}
	@echo "\033[38;2;0;80;255m"".philo executable deleted""\033[0m"	

re: fclean all

.PHONY: all clean fclean re