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

static t_node	*previous(t_node *head, char *name)
{
	while (ft_strcmp(head->name, name))
		head = head->next;
	return (head);
}

static void	print_way(t_node *s, t_node *e, t_node *node)
{
	t_node	*head;
	t_list	*list;

	head = node;
	if (!(e->previous))
		error();
	printf("%s", e->name);
	while (ft_strcmp(e->name, s->name))
	{
		printf("-%s", e->previous);
		e = previous(head, e->previous);
	}
	printf("\n");
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

int		main(int ac, char **av)
{
	t_farm	f;
	t_node	*s;
	t_node	*e;
	t_node	*node;

	f = ft_read(ac, av[1], &node);
	e = end(node);
	s = start(node);
	node = create_reserve(node);
	find_way(&node, s);
	print_way(s, e, node);
	return (1);
}
