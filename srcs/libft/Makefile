# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 15:28:58 by oelbelam          #+#    #+#              #
#    Updated: 2019/09/29 16:10:37 by oelbelam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all : $(NAME)
$(NAME):
	@gcc -c -Wall -Werror -Wextra *.c
	@ar rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
