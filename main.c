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

static void	print_node(t_node *node)
{
	while (node->next)
	{
		printf("name = %s\n", node->name);
		printf("start = %d\n", node->start);
		printf("end = %d\n", node->end);
		printf("visit = %d\n", node->visit);
		printf("x = %d\n", node->x);
		printf("y = %d\n", node->y);
		while (node->kid)
		{
			printf("linked with = %s\n", node->kid->name);
			node->kid = node->kid->next;
		}
		printf("\n");
		node = node->next;
	}
}

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
	t_node	*node;

	f = ft_read(ac, av[1], &node);
	end(node);
	s = start(node);
	find_way(&node, s);
	print_node(node);
	ft_printf("fd = %d, ants = %d\n", f.fd, f.ants);
}
