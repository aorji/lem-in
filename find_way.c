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
	int	i;
	t_node	*end;

	i = 0;
	while (node->next)
	{
		if (node->end)
		{
			end = node;
			i++;
		}
		node = node->next;
	}
	(i != 1) ? error() : 0;
	return (end);
}

t_node	*start(t_node *node)
{
	int i;
	t_node	*start;

	i = 0;
	while (node->next)
	{
		if (node->start)
		{
			start = node;
			i++;
		}
		node = node->next;
	}
	(i != 1) ? error() : 0;
	return (start);
}

void	find_way(t_node **node, t_node *current) 
{
	t_node	*tmp;

	tmp = *node;
	if (current->end)
		return ;
	if (!(current->kid))
		return ;
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
