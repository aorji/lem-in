/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:10 by aorji             #+#    #+#             */
/*   Updated: 2018/05/09 14:46:13 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*end(t_node *node)
{
	while (node->next)
	{
		if (node->end)
			return (node);
		node = node->next;
	}
	error();
	return (node);
}

t_node	*start(t_node *node)
{
	while (node->next)
	{
		if (node->start)
			return (node);
		node = node->next;
	}
	error();
	return (node);
}

void	find_way(t_node **node, t_node *current) 
{
	t_node	*tmp;

	// printf("%s\n", current->name);
	tmp = *node;
	if (current->end)
		return ;
	if (!(current->kid))
		return ;
	// printf("%s %s %d\n", current->name, current->kid->name, current->step);
	while (tmp->next && ft_strcmp(tmp->name, current->kid->name))
		tmp = tmp->next;
	if (!(tmp->next))
	{
		if (current->kid->next)
		{
			current->kid = current->kid->next;
			find_way(node, current);
		}
		return ;
	}
	if (tmp->step && (tmp->step <= (current->step + 1)))
	{
		if (tmp->end)
			return ;
		current->kid = current->kid->next;
		find_way(node, current);
		return ;
	}
	if (tmp->start)
	{
		current->kid = current->kid->next;
		find_way(node, current);
	}
	else
	{
		if (tmp->step > current->step + 1)
		{
			tmp->step = current->step + 1;
			tmp->kid = tmp->reserve;
			tmp->previous = current->name;
			find_way(node, tmp);
		}
		tmp->step = current->step + 1;
		tmp->previous = current->name;
		find_way(node, tmp);
		current->kid = current->kid->next;
		find_way(node, current);
	}
}
