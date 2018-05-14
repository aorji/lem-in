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

void	ft_reset(t_node **reset, t_node *node)
{
	*reset = node;
	while (node->next)
	{
		node->step = 0;
		node->previous = NULL;
		node->kid = node->reserve;
		node = node->next;
	}
}

t_node	*del(t_node *node, t_list *list, t_node *s, t_node *e)
{
	t_list	*head;
	t_node	*tmp;
	t_node	*new;
	
	head = list;
	while (list->next && node->next)
	{
		if (!ft_strcmp(node->name, list->content) && ft_strcmp(node->name, s->name) && ft_strcmp(node->name, e->name))
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
	// printf("node = %s\n", node->next->name);
		while (list->next)
		{
			// printf("list = %s\n", list->content);
			if (!ft_strcmp(node->next->name, list->content) && ft_strcmp(node->next->name, s->name) && ft_strcmp(node->next->name, e->name))
			{
				// printf("del node = %s\n", node->next->name);
				tmp = node->next;
				node->next = node->next->next;
				free(tmp);
			}
			list = list->next;
		}
		node = node->next;
	}
	return (new);
}
