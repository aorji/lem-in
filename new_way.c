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
		else
			list = list->next;
	}
	new = node;
	while (node->next && node->next->next)
	{
		list = head;
				// ft_printf("%s\n", head->content);
		while (list->next && node->next && !node->next->start && !node->next->end && node->next->next)
		{
			if (!ft_strcmp(node->next->name, list->content) && !(node->next->start) && !(node->next->end))
			{
				tmp = node->next;
				(node->next->next) ? (node->next = node->next->next) : (node->next = NULL);
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
