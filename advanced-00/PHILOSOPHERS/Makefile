# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 01:02:06 by aaboudra          #+#    #+#              #
#    Updated: 2025/08/27 21:39:20 by aaboudra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC =cc 
FLAGS = -Wall -Wextra -Werror
SRS = main.c parcer.c utils.c init.c memory_manage.c safety_op.c manager.c\
		simulation.c syncro_utils.c utils_2.c
OBG = $(SRS:.c=.o)
HEADER = philo.h

all: $(NAME)

$(NAME): $(OBG)
	@$(CC) $(FLAGS) $(OBG) -o $@
	@echo "Compilation of $(NAME) is complete!"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBG)

fclean: clean
	@rm -f $(NAME)

re: fclean all