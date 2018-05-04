# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorji <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 18:11:26 by aorji             #+#    #+#              #
#    Updated: 2018/01/25 18:11:28 by aorji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft.a
SRC = ft_buf1.c  ft_printf.c ft_buf.c ft_an.c ft_flags.c ft_additional.c ft_itoa.c ft_print_unicode.c ft_uu.c ft_cc.c ft_ss.c ft_print.c ft_pp.c ft_oo.c ft_print_spaces.c ft_xx.c ft_use_precision.c ft_ddi.c
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ cd ../libft && make
	@ ar rc $(NAME) $(OBJ) ../libft/*.o
	
%.o: %.c
	@ gcc $(FLG) -c -o $@ $<

clean:
	@ /bin/rm -rf $(OBJ)
	@ cd ../libft && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ /bin/rm -f libft/$(LIB)

re: fclean all
