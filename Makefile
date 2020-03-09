# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 15:24:50 by oelbelam          #+#    #+#              #
#    Updated: 2019/10/14 10:48:45 by oelbelam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = oelbelam.filler
SRCS = filler.c my_player.c info_init.c free_structs.c get_map.c get_the_score.c
OBJS = $(SRCS:.c=.o)
OBJ  = srcs/libft/libft.a srcs/libftprintf.a
DIR = srcs/libft
PRINT = srcs
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJS)
	make -C $(DIR) 
	make -C $(PRINT)
	gcc -o $(NAME) $(OBJS) $(OBJ)

clean:
	@make -C $(DIR) clean
	@make -C $(PRINT) clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@make -C $(DIR) fclean
	@make -C $(PRINT) fclean

re: fclean all

