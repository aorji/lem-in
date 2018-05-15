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

int		main(int ac, char **av)
{
	t_farm	f;
	int i = 0;
	t_node	*s;
	t_node	*e;
	t_node	*node;
	t_node	*reset;
	t_list	*list;

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
		print_way(list);
		if (!i)
		{
			f.way = list;
			f.min = list_len(list);
		}
		ft_printf("done\n");
		node = ft_reset(node);
		node = del(node, list, s, e);
		i++;
	}
	return (1);
}
