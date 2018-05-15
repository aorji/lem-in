/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:28:48 by aorji             #+#    #+#             */
/*   Updated: 2018/05/14 21:28:49 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*del(t_node *node, t_list *list, t_node *s, t_node *e)
{
	t_list	*head;
	t_node	*tmp;
	t_node	*new;
	
	head = list;

	while (list->next && node->next && !node->start && !node->end)
	{
		if (!ft_strcmp(node->name, list->content))
		{
			tmp = node;
			node = node->next;
			free(tmp);
			list = head;
		}
		list = list->next;
	}
	new = node;
	while (node->next && node->next->next)
	{
		list = head;
		while (list->next && node->next->name && !node->next->start && !node->next->end)
		{
			// printf("%s =? %s\n", node->next->name, list->content);
			if (!ft_strcmp(node->next->name, list->content) && ft_strcmp(node->next->name, s->name) && ft_strcmp(node->next->name, e->name))
			{
				// printf("%s\n", "== -> del");
				tmp = node->next;
				node->next = node->next->next;
				list = head;
				free(tmp);
			}
			else
				list = list->next;
		}
		node = node->next;
	}
	return (new);
}
