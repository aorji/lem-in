/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:05:51 by aorji             #+#    #+#             */
/*   Updated: 2018/05/01 13:05:55 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

typedef	struct		s_node
{
	char			*name;
	int				start;
	int				end;
	char			*links;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef	struct		s_farm
{
	int				ants;
	int				rooms;
	int				fd;
}					t_farm;

typedef	struct		s_map
{
	char			**arr;
}					t_map;

int		isnum(char *s);
void	check_spaces(char *line);
t_node	*rooms(t_farm *f, t_node *node);
void	ants_num(t_farm *f);
void	error();
