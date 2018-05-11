/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:36:39 by aorji             #+#    #+#             */
/*   Updated: 2018/05/07 14:36:41 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	check_repeat(char *arr, t_node *head)
{
	while (head->next)
	{
		if (!ft_strcmp(head->name, arr))
			error();
		head = head->next;
	}
}

static t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->start = 0;
	node->end = 0;
	node->step = 0;
	node->previous = NULL;
	node->kid = NULL;
	node->reserve = NULL;
	node->next  = NULL;
	return (node);
}

static t_node	*fill_node(t_node *node, char **arr)
{
	node->name = ft_strcpy(ft_strnew(ft_strlen(arr[0])), arr[0]);
	node->x = ft_atoi(arr[1]);
	node->y = ft_atoi(arr[2]);
	node->next = new_node();
	return (node);
}

int				rooms(t_farm *f, t_node **head)
{
	t_node	*node;
	char	**arr;
	char	*line;

	node = new_node();
	*head = node;
	while (get_next_line(f->fd, &line) == 1)
	{
		arr = ft_strsplit(line, ' ');
		if (!ft_strcmp(line, "##start"))
			node->start = 1;
		else if (!ft_strcmp(line, "##end"))
			node->end = 1;
		else if (arrlen(arr) == 3 && isnum(arr[1]) && isnum(arr[2]))
		{
			(arr[0][0] == 'L') ? error() : 0;
			check_spaces(line);
			check_repeat(arr[0], *head);
			node = fill_node(node, arr);
			node = node->next;
			arrdel(&arr);
		}
		else if (line[0] == '#')
			continue ;
		else
			return (link_info(f->fd, line, head));
		arrdel(&arr);
	}
	error();
	return (1);
}

void			ants_num(t_farm *f)
{
	char	*line;
	int		n;

	if (get_next_line(f->fd, &line) == 1)
	{
		if (isnum(line) && ((n = ft_atoi(line)) > 0))
			f->ants = n;
		else if (line[0] == '#')
			ants_num(f);
		else
			error();
	}
}
