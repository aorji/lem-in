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

static t_node	*create_reserve(t_node *node)
{
	t_node	*head;

	head = node;

	while(node->next)
	{
		node->reserve = node->kid;
		node = node->next;
	}
	return (head);
}

t_farm	ft_read(int ac, char *av, t_node **head)
{
	t_farm	f;
	t_node	*node;

	f.fd = (ac == 2) ? open(av, O_RDONLY) : 0;
	ants_num(&f);
	rooms(&f, &node);
	*head = node;
	close(f.fd);
	return (f);
}

static t_node	*node_cpy(t_node *reset, t_node *node)
{
	t_node *head;

	head = reset;
	while (node->next)
	{
		reset->name = node->name;
		reset->start = node->start;
		reset->end = node->end;
		reset->kid = node->kid;
		reset->reserve = node->reserve;
		reset->x = node->x;
		reset->y = node->y;
		reset->next = new_node();
		reset = reset->next;
		node = node->next;
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_farm	f;
	t_node	*s;
	t_node	*e;
	t_node	*node;
	t_node	*reset;
	t_list	*list;

	f = ft_read(ac, av[1], &node);
	node = create_reserve(node);
	reset = new_node();
	reset = node_cpy(reset, node);
	while (f.ants)
	{
		e = end(node);
		s = start(node);
		find_way(&node, s);
		list = create_way(s, e, node);
		print_way(list);
		printf("done\n");
		node = del(reset, list, s, e);
		f.ants--;
	}
	// print_node(node);
	return (1);
}
