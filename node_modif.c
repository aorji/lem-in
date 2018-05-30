/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:08:12 by aorji             #+#    #+#             */
/*   Updated: 2018/05/15 18:08:13 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*node_cpy(t_node *node)
{
	t_node	*head;
	t_node	*reset;

	reset = new_node();
	head = reset;
	while (node->next)
	{
		reset->name = node->name;
		reset->start = node->start;
		reset->end = node->end;
		reset->kid = node->kid;
		reset->reserve = node->reserve;
		reset->x = node->x;
		reset->y = node->y;
		reset->next = new_node();
		reset = reset->next;
		node = node->next;
	}
	return (head);
}

int		ft_reset(t_node **node, t_list *list, t_node *s, t_node *e)
{
	t_node *head;

	head = *node;
	while (head->next)
	{
		head->step = 0;
		head->previous = NULL;
		head->kid = head->reserve;
		head = head->next;
	}
	del(node, list, s, e);
	return (1);
}

void	create_reserve(t_node **node)
{
	t_node	*head;

	head = *node;
	while (head->next)
	{
		head->reserve = head->kid;
		head = head->next;
	}
}
