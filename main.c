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

int		error(void)
{
	ft_printf("%s\n", "ERROR");
	exit(1);
	return (1);
}

t_farm	ft_read(int ac, char *av, t_node **head, char **buff)
{
	t_farm	f;
	t_node	*node;

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

static t_holder	*new_holder()
{
	t_holder	*new;

	new = (t_holder *)malloc(sizeof(t_holder));
	new->next = NULL;
	return (new);
}

int		main(int ac, char **av)
{
	t_farm	f;
	int		i;
	t_node	*s;
	t_node	*e;
	t_node	*node;
	t_node	*reset;
	t_list	*list;
	t_holder *lh;
	t_holder *head;
	char	*buff;
	t_list	*tmp;
	t_list	*tmp3;
	t_node	*tmp1;
	t_node	*tmp2;

	i = 0;
	lh = new_holder();
	head = lh;
	f = ft_read(ac, av[1], &node, &buff);
	create_reserve(&node);
	reset = node_cpy(node);
	while (i < f.ants)
	{
		s = start(node);
		find_way(&node, s);
		e = end(node);
		if (e->previous == NULL)
		{
			if (!i)
				error();
			tmp1 = node;
			node = node_cpy(reset);
			while (tmp1)
			{
				tmp2 = tmp1;
				tmp1 = tmp1->next;
				free(tmp2);
			}
			continue ;
		}
		list = create_way(s, e, node);
		if (f.min && ((list_len(list) - 1)- f.min) > (f.ants - i))
			list = f.way;
		else
		{
			ft_list_reverse(&list);
			tmp = list;
			list = list->next;
			free(tmp);
		}
		lh->lst = list;
		lh->res = list; //tut
		lh->next = new_holder();
		lh = lh->next;
		if (!i)
		{
			f.way = list;
			f.min = list_len(list);
		}
		ft_reset(&node);
		del(&node, list, s, e);
		i++;
	}
	ft_printf("%s\n", buff);
	ft_strdel(&buff);
	print_way(head, e);
	return (1);
}
