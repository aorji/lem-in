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

int				error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(1);
	return (1);
}

t_farm			ft_read(int ac, char *av, t_node **head, char **buff)
{
	t_farm		f;
	t_node		*node;

	*buff = ft_strnew(0);
	f.fd = (ac == 2) ? open(av, O_RDONLY) : 0;
	f.way = NULL;
	f.min = 0;
	ants_num(&f, buff);
	rooms(&f, &node, buff);
	*head = node;
	close(f.fd);
	return (f);
}

int				main(int ac, char **av)
{
	t_farm		f;
	t_node		*node;
	t_node		*reset;
	t_holder	*head;
	char		*buff;

	f = ft_read(ac, av[1], &node, &buff);
	create_reserve(&node);
	head = loop(&f, &node, node_cpy(node));
	ft_printf("%s\n", buff);
	ft_strdel(&buff);
	print_way(head, end(node));
	// system("leaks -q lem-in");
	return (1);
}
