/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:56:22 by aorji             #+#    #+#             */
/*   Updated: 2018/05/22 15:56:23 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		free_br(t_node *node)
{
	t_node	*tmp;
	t_kids	*k_tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = NULL;
		node = tmp;
	}
	node = NULL;
	return (1);
}

void	free_start(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		(lst->content) ? free(lst->content) : 0;
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

void	free_node(t_node *tmp1)
{
	t_node		*tmp2;

	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
}
