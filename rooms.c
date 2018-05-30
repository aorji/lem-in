/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:25:32 by aorji             #+#    #+#             */
/*   Updated: 2018/05/14 21:25:34 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_node	*fill_room(t_node *node, char **arr)
{
	node->name = ft_strcpy(ft_strnew(ft_strlen(arr[0])), arr[0]);
	node->x = ft_atoi(arr[1]);
	node->y = ft_atoi(arr[2]);
	node->next = new_node();
	return (node);
}

static void		create_room(char **arr, char *line,
	t_node **head, t_node **node)
{
	t_node *tmp;

	(arr[0][0] == 'L') ? error() : 0;
	check_spaces(line);
	tmp = node_cpy(*head);
	check_doub(&tmp, ft_atoi(arr[1]), ft_atoi(arr[2]));
	free_br(tmp);
	check_repeat(arr[0], *head);
	*node = fill_room(*node, arr);
	*node = (*node)->next;
}

int				rooms(t_farm *f, t_node **head, char **buff)
{
	t_node	*node;
	t_node	*test;
	char	**arr;
	char	*line;

	node = new_node();
	*head = node;
	while (get_next_line(f->fd, &line) == 1)
	{
		*buff = noleak_strjoin(*buff, line, buff);
		*buff = noleak_strjoin(*buff, "\n", buff);
		arr = ft_strsplit(line, ' ');
		(!ft_strcmp(line, "##start")) ? node->start = 1 : 0;
		(!ft_strcmp(line, "##end")) ? node->end = 1 : 0;
		if (arrlen(arr) == 3 && isnum(arr[1]) && isnum(arr[2]))
			create_room(arr, line, head, &node);
		else if (line[0] == '#' && ft_strdel(&line) && arrdel(arr))
			continue ;
		else
			return (arrdel(arr) && link_info(f->fd, &line, head, buff));
		arrdel(arr);
		ft_strdel(&line);
	}
	error();
	return (1);
}

void			ants_num(t_farm *f, char **buff)
{
	char	*line;
	int		n;

	if (get_next_line(f->fd, &line) == 1)
	{
		*buff = noleak_strjoin(*buff, line, buff);
		*buff = noleak_strjoin(*buff, "\n", buff);
		if (isnum(line) && ((n = ft_atoi(line)) > 0))
			f->ants = n;
		else if (line[0] == '#')
		{
			ft_strdel(&line);
			ants_num(f, buff);
		}
		else
		{
			ft_strdel(&line);
			ft_strdel(buff);
			error();
		}
		ft_strdel(&line);
	}
}
