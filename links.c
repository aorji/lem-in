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

// static t_node	*create_link(t_node *node, char *name, char *link)
// {
// 	// t_node	*head;

// 	// head = node;
// 	// node->kid = (t_kids *)malloc(sizeof(t_kids));
// 	// node->kid->next = NULL;
// 	// printf("start with %s\n", node->name);
// 	// while (node->next)
// 	// {
// 	// 	if (!ft_strcmp(name, node->name))
// 	// 	{
// 	// 		printf("node = %s\n", node->name);
// 	// 		if (node)
// 	// 			node->kid->name = "1"; //ft_strcpy(ft_strnew(ft_strlen(link)), link);
// 	// 		else
// 	// 			printf("%s\n", "????");
// 	// 		// (*node)->kid->next = (t_kids *)malloc(sizeof(t_kids));
// 	// 		// printf("kid = %s\n", (*node)->kid->name);
// 	// 		// (*node)->kid = (*node)->kid->next;
// 	// 		// (*node)->kid->next = NULL;
// 	// 		return (head);
// 	// 	}
// 	// 	node = node->next;
// 	// }
// 	// error();
// 	// return (head);
// }

int			link_info(int fd, char *line, t_node **node)
{
	char	**arr;
	// t_node	*head;

	// head = *node;
	arr = ft_strsplit(line, '-');
	// if (arrlen(arr) == 2)
	// {
	// 	// *node = create_link(head, arr[0], arr[1]);
	// 	// *node = create_link(head, arr[1], arr[0]);

	// }
	if ((arrlen(arr) != 2) && !(line[0] == '#') && (line[1] != '#')) 
		error();
	else if (get_next_line(fd, &line) == 1)
		link_info(fd, line, node);
	else
		return (1);
	return (1);
}
