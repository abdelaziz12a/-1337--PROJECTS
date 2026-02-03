# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 19:50:43 by aaboudra          #+#    #+#              #
#    Updated: 2025/03/04 23:18:54 by aaboudra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRS = main.c ft_split.c init_stack.c errors.c utils_stack.c \
		swap_rotate.c push_r_rotate.c utils_sort.c push_swap.c \

OBJ = $(SRS:.c=.o)

HEADER = push_swap.h

all: $(NAME)



$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "Compilation of $(NAME) is complete!"

%.o: %.c  $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"
	
clean:
	rm -f $(OBJ)
	
fclean:  clean
	rm -f $(NAME)
	
re: fclean all