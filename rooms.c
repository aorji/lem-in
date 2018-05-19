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

static void		check_repeat(char *arr, t_node *head)
{
	while (head->next)
	{
		if (!ft_strcmp(head->name, arr))
			error();
		head = head->next;
	}
}

static void		check_doub(t_node *head, int i, int j)
{
	while (head)
	{
		if ((head->x == i) && (head->y == j))
			error();
		head = head->next;
	}
}

static t_node	*fill_room(t_node *node, char **arr)
{
	node->name = ft_strcpy(ft_strnew(ft_strlen(arr[0])), arr[0]);
	node->x = ft_atoi(arr[1]);
	node->y = ft_atoi(arr[2]);
	node->next = new_node();
	return (node);
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
		*buff = ft_strjoin(*buff, line);
		*buff = ft_strjoin(*buff, "\n");
		arr = ft_strsplit(line, ' ');
		if (!ft_strcmp(line, "##start"))
			node->start = 1;
		else if (!ft_strcmp(line, "##end"))
			node->end = 1;
		else if (arrlen(arr) == 3 && isnum(arr[1]) && isnum(arr[2]))
		{
			(arr[0][0] == 'L') ? error() : 0;
			check_spaces(line);
			check_doub(node_cpy(*head), ft_atoi(arr[1]), ft_atoi(arr[2]));
			check_repeat(arr[0], *head);
			node = fill_room(node, arr);
			node = node->next;
			arrdel(&arr);
		}
		else if (line[0] == '#')
			continue ;
		else
			return (link_info(f->fd, line, head, buff));
		arrdel(&arr);
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
		*buff = ft_strjoin(*buff, line);
		*buff = ft_strjoin(*buff, "\n");
		if (isnum(line) && ((n = ft_atoi(line)) > 0))
			f->ants = n;
		else if (line[0] == '#')
			ants_num(f, buff);
		else
			error();
	}
}
