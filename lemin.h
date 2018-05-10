/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:05:51 by aorji             #+#    #+#             */
/*   Updated: 2018/05/01 13:05:55 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_kids
{
	char			*name;
	struct s_kids	*next;
	struct s_kids	*pr;
}					t_kids;

typedef	struct		s_node
{
	char			*name;
	int				start;
	int				end;
	t_kids			*kid;
	t_kids			*reserve;
	int				x;
	int				y;
	int				visit;
	int				step;
	struct s_node	*next;
}					t_node;

typedef	struct		s_farm
{
	int				ants;
	int				fd;
}					t_farm;

typedef	struct		s_map
{
	char			**arr;
}					t_map;

/*
**main.c
*/
int					main(int ac, char **av);
t_farm				ft_read(int ac, char *av, t_node **head);
void				error();

/*
**validation.c
*/
int					isnum(char *s);
void				check_spaces(char *line);
void				check_dash(char *line);
int					check_elem(char *a, char *b, char *c);

/*
**fill_info.c
*/
int					rooms(t_farm *f, t_node **head);
void				ants_num(t_farm *f);

/*
**links.c
*/
int					link_info(int fd, char *line, t_node **node);

/*
**find_way.c
*/
t_node				*end(t_node *node);
t_node				*start(t_node *node);
void				find_way(t_node **node, t_node *current);
#endif
