/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:17 by aorji             #+#    #+#             */
/*   Updated: 2018/05/07 20:24:20 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_kids	*new_kid(void)
{
	t_kids	*new;
	new = (t_kids*)malloc(sizeof(t_kids));
	new->next = NULL;
	// new->pr = NULL;
	return (new);
}

static void		create_link(t_node **node, char *name, char *link)
{
	t_node	*head;
	t_kids	*tmp;

	head = *node;
	while (head->next)
	{
		if (!ft_strcmp(head->name, name))
		{
			if (head->kid)
			{
				tmp = head->kid;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = new_kid();
				tmp = tmp->next;
				tmp->name = ft_strcpy(ft_strnew(ft_strlen(link)), link);
				return;
			}
			head->kid = new_kid();
			head->kid->name = ft_strcpy(ft_strnew(ft_strlen(link)), link);
			return ;
		}
		head = head->next;
	}
	error();
}

int			link_info(int fd, char *line, t_node **node)
{
	char	**arr;

	arr = ft_strsplit(line, '-');
	check_dash(line);
	if (arrlen(arr) == 2)
	{
		create_link(node, arr[0], arr[1]);
		create_link(node, arr[1], arr[0]);
	}
	if ((arrlen(arr) != 2) && !(line[0] == '#') && (line[1] != '#'))
	{
		arrdel(&arr);
		error();
	}
	else if ((get_next_line(fd, &line) == 1) && arrdel(&arr))
		link_info(fd, line, node);
	else
		return (arrdel(&arr));
	return (1);
}
