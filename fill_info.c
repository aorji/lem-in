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

#include "lem-in.h"

int	find_node(t_node *node, char *s)
{
	while (node)
	{
		if (!ft_strcmp(node->name, arr[0]))
			return (1);
		node = node->next;
	}
	return (0);

}

static int link_info(char *line, int fd, t_node *node)
{
	arr = ft_strsplit(line, '-');
	if (arrlen(arr) == 2 && find_node(node, arr[0]) && find_node(node, arr[1]))
		return (1);

	
}

t_node	*fill_node(t_node *node, char **arr, int s, int e)
{
	node->name = ft_strcpy(ft_strnew(ft_strlen(arr[0])), arr[0]);
	node->start = s;
	node->end = e;
	node->x = ft_atoi(arr[1]);
	node->y = ft_atoi(arr[2]);
	node->next  = (t_node *)malloc(sizeof(t_node));
	node = node->next;
	return (node);
}

int		rooms(t_farm *f, t_node **head)
{
	t_node	*node;
	char	*line;
	char	**arr;
	int		s;
	int		e;

	s = 0;
	e = 0;
	node = (t_node *)malloc(sizeof(t_node));
	node->next = NULL;
	*head = node;
	while (get_next_line(f->fd, &line) == 1)
	{
		arr = ft_strsplit(line, ' ');
		if (!ft_strcmp(line, "##start"))
			s = 1;
		else if (!ft_strcmp(line, "##end"))
			e = 1;
		else if ((line[0] == '#') && (line[1] != '#'))
			continue; 
		else if ((arrlen(arr) == 3) && check_elem(arr[0], arr[1], arr[2]))
		{
			check_spaces(line);
			node = fill_node(node, arr, s, e);
			s = 0;
			e = 0;
		}
		else
		{
			free(node);
			node = NULL;
			arrdel(&arr);
			return(link_info(line, f->fd, *head));
		}
		arrdel(&arr);
	}
	error();
	return (1);
}

void	ants_num(t_farm *f)
{
	char	*line;
	int		n;

	if (get_next_line(f->fd, &line) == 1)
	{
		if (isnum(line) && ((n = ft_atoi(line)) > 0))
			f->ants = n;
		else if ((line[0] == '#') && (line[1] != '#'))
			ants_num(f);
		else
			error();
	}
}
