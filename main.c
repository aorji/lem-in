/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:15:54 by aorji             #+#    #+#             */
/*   Updated: 2018/04/30 18:16:05 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(1);
}

t_farm	ft_read(int ac, char *av, t_node **head)
{
	t_farm	f;
	t_node	*node;

	f.fd = (ac == 2) ? open(av, O_RDONLY) : 0;
	f.way = NULL;
	f.min = 0;
	ants_num(&f);
	rooms(&f, &node);
	*head = node;
	close(f.fd);
	return (f);
}

static int	list_len(t_list *list)
{
	int i = 0;

	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i);

}

static t_holder	*new_holder()
{
	t_holder	*new;

	new = (t_holder *)malloc(sizeof(t_holder));
	new->lst = ft_lstnew(NULL, 0);
	new->next = NULL;
	return (new);
}

static void	ft_list_reverse(t_list **begin_list)
{
	t_list		*curr;
	t_list		*next;
	t_list		*prev;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}

int		main(int ac, char **av)
{
	t_farm	f;
	int i = 0;
	t_node	*s;
	t_node	*e;
	t_node	*node;
	t_node	*reset;
	t_list	*list;
	t_holder *lh;
	t_holder *head;

	lh = new_holder();
	head = lh;
	f = ft_read(ac, av[1], &node);
	node = create_reserve(node);
	reset = new_node();
	reset = node_cpy(reset, node);
	while (i < f.ants)
	{
		s = start(node);
		find_way(&node, s);
		e = end(node);
		if (e->previous == NULL)
		{
			node = node_cpy(node, reset);
			continue ;
		}
		list = create_way(s, e, node);
		if (f.min && (list_len(list) - f.min) > (f.ants - i))
			list = f.way;
		ft_list_reverse(&list);
		list = list->next;
		lh->lst = list;
		lh->next = new_holder();
		lh = lh->next;
		if (!i)
		{
			f.way = list;
			f.min = list_len(list);
		}
		node = ft_reset(node);
		node = del(node, list, s, e);
		i++;
	}
	print_way(head, e);
	return (1);
}
