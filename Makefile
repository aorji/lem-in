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

NAME	=	lem-in
FLG		=	-Wall -Wextra -Werror
H 		=	lemin.h
SRC		=	main.c validation.c rooms.c links.c find_way.c unused.c \
			print_way.c new_way.c node_modif.c
OBJ		=	$(SRC:.c=.o)
PRNTF	=	ft_printf/libftprintf.a

all: $(NAME) 

$(NAME): $(OBJ) $(H)
	@ make -C ft_printf
	@ gcc $(FLG) -o $(NAME) $(OBJ) -I.$(H) $(PRNTF)

clean:
	@ make clean -C ./ft_printf
	@ /bin/rm -f $(OBJ) $(OBJ) lem-in.h.gch

fclean: clean
	@ make fclean -C ./ft_printf
	@ /bin/rm -f $(NAME) $(NAME) $(PRNTF)

re: fclean all
