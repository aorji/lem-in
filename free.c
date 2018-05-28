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

int	free_node(t_node *node)
{
	t_node	*tmp;
	t_kids	*k_tmp;

	while (node)
	{
		if (node->name)
		{
			ft_strdel(&(node->name));
			while (node->kid)
			{
				if (node->kid->name)
					ft_strdel(&(node->kid->name));
				k_tmp = node->kid->next; 
				free(node->kid);
				node->kid = NULL;
				node->kid = k_tmp;
			}
		}
		tmp = node;
		node = node->next;
		free(tmp);
		tmp = NULL;
	}
	return (1);
}

int	free_br(t_node *node)
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

void	lstdel(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

int	free_lh(t_holder *lh)
{
	t_holder	*tmp;
	t_list		*tmpl;

	while (lh)
	{
		lstdel(lh->res);
		tmp = lh;
		lh = lh->next;
		free(tmp);
	}
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

