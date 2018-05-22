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

int	free_node(t_node **n)
{
	t_node *node;

	node = *n;
	while (node)
	{
		(node->name) ? free(node->name) : 0;
		while (node->kid)
		{
			(node->kid->name) ? free(node->kid->name) : 0;
			node->kid = node->kid->next;
		}
		free(node->kid);
		while (node->reserve)
		{
			(node->reserve->name) ? free(node->reserve->name) : 0;
			node->reserve = node->reserve->next;
		}
		node = node->next;
	}
	return (1);
}

int	free_lh(t_holder **lh)
{
	t_holder *h;

	h = *lh;
	while (h)
	{
		lstdel(&(h->lst));
		free(h);
		h = h->next;
	}
	return (1);
}

void	lstdel(t_list **list)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *list;
	while (lst)
	{
		(lst->content) ? free(lst->content) : 0;
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst);
	lst = NULL;
}