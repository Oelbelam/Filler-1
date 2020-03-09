# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 20:18:54 by oelbelam          #+#    #+#              #
#    Updated: 2019/10/08 21:43:24 by oelbelam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = srcs
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR) $(OBJ_DIR)/f_conv $(OBJ_DIR)/u_conv $(OBJ_DIR)/p_conv
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = .

FILE_NAMES = ft_printf.c c_conv.c d_conv.c d_solv1.c d_solv2.c itoa_base.c \
			o_conv_1.c o_conv.c s_conv.c spc_perc_strct.c stock_flag_1.c stock_flag.c \
			x_c_conv_1.c x_c_conv.c x_conv_1.c x_conv.c \
			f_conv/f_chk.c f_conv/ft_add_str.c f_conv/ft_pow_str.c f_conv/f_conv.c \
			f_conv/f_solv.c f_conv/print_float.c f_conv/ft_mult_str.c f_conv/rounding.c \
			f_conv/manipulat_flag0_flag.c f_conv/dbl_num.c f_conv/rounding1.c \
			f_conv/get_flags.c f_conv/rounding2.c u_conv/u_conv.c u_conv/u_solv.c p_conv/p_conv.c

SRC_FILES = $(addprefix $(SRC_DIR)/,$(FILE_NAMES))
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(FILE_NAMES:.c=.o))

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ_FILES)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)
$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIRS)
	gcc -c -Wall -Werror -Wextra -I $(INC_DIR) $^ -o $@
$(OBJ_DIRS):
	@mkdir $(OBJ_DIRS)
$(LIBFT):
	@make -C $(LIBFT_DIR)
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all
