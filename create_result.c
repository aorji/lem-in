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

static t_holder	*new_holder(void)
{
	t_holder	*new;

	new = (t_holder *)malloc(sizeof(t_holder));
	new->next = NULL;
	return (new);
}

static void	fill_lh(t_holder **lh, t_list **list)
{
	(*lh)->lst = (*list);
	(*lh)->res = (*list);
	(*lh)->next = new_holder();
	(*lh) = (*lh)->next;
}

static void	reverse(t_list **list)
{
	t_list		*tmp;

	ft_list_reverse(list);
	tmp = (*list);
	(*list) = (*list)->next;
	free(tmp);
}

static void	free_node(t_node *tmp1)
{
	t_node		*tmp2;

	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
}

static void	fill_shortest(t_farm *f, t_list *list)
{
	f->way = list;
	f->min = list_len(list);
}

t_holder	*loop(t_farm *f, t_node **node, t_node *reset)
{
	int			i;
	t_holder	*lh;
	t_holder	*head;
	t_list		*list;
	t_node		*tmp1;
	t_node		*s;
	t_node		*e;

	lh = new_holder();
	head = lh;
	i = 0;
	while (i < (*f).ants)
	{
		s = start(*node);
		find_way(node, s);
		e = end(*node);
		if (e->previous == NULL)
		{
			(!i) ? error() : 0;
			tmp1 = *node;
			*node = node_cpy(reset);
			free_node(tmp1);
			continue ;
		}
		list = create_way(s, e, *node);
		if ((*f).min && ((list_len(list) - 1) - (*f).min) > ((*f).ants - i))
			list = (*f).way;
		else
			reverse(&list);
		fill_lh(&lh, &list);
		(!i) ? fill_shortest(f, list) : 0;
		ft_reset(node, list, s, e);
		i++;
	}
	return (head);
}