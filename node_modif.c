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

t_node	*node_cpy(t_node *reset, t_node *node)
{
	t_node *head;

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

t_node	*ft_reset(t_node *node)
{
	t_node *head;

	head = node;
	while (node->next)
	{
		node->step = 0;
		node->previous = NULL;
		node->kid = node->reserve;
		node = node->next;
	}
	return (head);
}

t_node	*create_reserve(t_node *node)
{
	t_node	*head;

	head = node;

	while(node->next)
	{
		node->reserve = node->kid;
		node = node->next;
	}
	return (head);
}