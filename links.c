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

#include "lem-in.h"

static int	create_link(t_node **node, char *name, char *link)
{
	t_node	*head;

	head = *node;
	while (head->next)
	{
		if (!ft_strcmp(head->name, name))
		{
			printf("%s-%s\n", name, link);
			return (1);
		}
		head = head->next;
	}
	error();
	return (1);
}

int			link_info(int fd, char *line, t_node **node)
{
	char	**arr;

	printf("line = %s\n", line);
	arr = ft_strsplit(line, '-');
	if (arrlen(arr) == 2)
	{
		create_link(node, arr[0], arr[1]);
		create_link(node, arr[1], arr[0]);
	}
	if ((arrlen(arr) != 2) && !(line[0] == '#') && (line[1] != '#')) 
		error();
	else if (get_next_line(fd, &line) == 1)
		link_info(fd, line, node);
	else
		return (1);
	return (1);
}
