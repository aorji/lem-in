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

	tmp = *node;
	printf("%s-", current->name);
	while (ft_strcmp(tmp->name, current->kid->name))
		tmp = tmp->next;
	if (tmp->visit)
	{printf("%s\n", "visit");
		current->kid = current->kid->next;
		//exit(1);
		find_way(node, current);
	}
	else
	{
		tmp->step++;
		tmp->visit = 1;
		printf("%s\n", tmp->name);
		//exit(1);
		find_way(node, tmp);
	}
}
