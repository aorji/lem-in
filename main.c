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

#include "lem-in.h"

void	error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(1);
}

t_farm	ft_read(int ac, char *av)
{
	t_farm	f;
	t_node	*node;

	f.fd = (ac == 2) ? open(av, O_RDONLY) : 0;
	ants_num(&f);
	rooms(&f, &node);
	close(f.fd);
	while (node)//ПОЧЕМУ NEXT?????
	{
		printf("name = %s\n", node->name);
		printf("s = %d\n", node->start);
		printf("e = %d\n", node->end);
		printf("x = %d\n", node->x);
		printf("y = %d\n", node->y);
		node = node->next;
	}
	return (f);
}

int		main(int ac, char **av)
{
	t_farm	f;

	f = ft_read(ac, av[1]);
	ft_printf("fd = %d, ants = %d\n", f.fd, f.ants);
}
