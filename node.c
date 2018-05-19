/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 22:08:19 by aorji             #+#    #+#             */
/*   Updated: 2018/05/17 22:08:23 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->start = 0;
	node->end = 0;
	node->step = 0;
	node->previous = NULL;
	node->kid = NULL;
	node->reserve = NULL;
	node->next = NULL;
	return (node);
}

t_node	*fill_node(t_node *node, char **arr)
{
	node->name = ft_strcpy(ft_strnew(ft_strlen(arr[0])), arr[0]);
	node->x = ft_atoi(arr[1]);
	node->y = ft_atoi(arr[2]);
	node->next = new_node();
	return (node);
}
