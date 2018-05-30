/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:52:53 by aorji             #+#    #+#             */
/*   Updated: 2018/05/30 15:52:56 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	reverse(t_list **list)
{
	t_list		*tmp;

	ft_list_reverse(list);
	tmp = (*list);
	(*list) = (*list)->next;
	free(tmp);
}

static void	fill_shortest(t_farm *f, t_list *list)
{
	f->way = list;
	f->min = list_len(list);
}

static int	if_not_prev(t_node *reset, t_node **node, int i, t_node *e)
{
	t_node		*tmp1;

	if (e->previous == NULL)
	{
		(!i) ? error() : 0;
		tmp1 = *node;
		*node = node_cpy(reset);
		free_node(tmp1);
		return (1);
	}
	return (0);
}

t_holder	*loop(t_farm *f, t_node **node, t_node *reset, int i)
{
	t_holder	*lh;
	t_holder	*head;
	t_list		*list;
	t_node		*s;
	t_node		*e;

	lh = new_holder();
	head = lh;
	while (i < (*f).ants)
	{
		s = start(*node);
		find_way(node, s, *node);
		e = end(*node);
		if (if_not_prev(reset, node, i, e))
			continue;
		list = create_way(s, e, *node);
		if ((*f).min && ((list_len(list) - 1) - (*f).min) > ((*f).ants - i))
			list = (*f).way;
		else
			reverse(&list);
		fill_holder(&lh, &list);
		(!i) ? fill_shortest(f, list) : 0;
		ft_reset(node, list, s, e) && i++;
	}
	return (head);
}
