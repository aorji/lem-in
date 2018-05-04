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

void	error()
{
	ft_printf("%s\n", "ERROR");
	exit(1);
}

int 	check_elem(char *a, char *b, char *c)
{
	if (isnum(b) && isnum(c) && a[0] != 'L' && a[0] != '#')
		return (1);
	return (0);
}

t_node	*rooms(t_farm *f, t_node *node)
{
	char	*line;
	char	**arr;
	t_node	*head;
	int i = 0;
	int s;
	int e;

	s = 0;
	e = 0;
	head = node;
	f->rooms = 0;
	while (get_next_line(f->fd, &line) == 1)
	{
		arr = ft_strsplit(line, ' ');
		if (!ft_strcmp(line, "##start"))
			s = 1;
		else if (!ft_strcmp(line, "##end"))
			e = 1;
		else if ((arrlen(arr) == 3) && check_elem(arr[0], arr[1], arr[2]))
		{
			check_spaces(line);
			node->name = ft_strcpy(ft_strnew(ft_strlen(arr[0])), arr[0]);
			node->start = s;
			node->end = e;
			node->x = ft_atoi(arr[1]);
			node->y = ft_atoi(arr[2]);
			node->next  = (t_node *)malloc(sizeof(t_node));
			node = node->next;
			i++; // А НУЖНО ЛИ ??
			s = 0;
			e = 0;
		}
		else
		{
			// free(&(node->name)); !!!!!
			node = NULL;
			f->rooms = i;
			return (head);
		}
		arrdel(&arr);
	}
	error();
	return (head);
}

void	ants_num(t_farm *f)
{
	char	*line;
	int		n;

	if (get_next_line(f->fd, &line) == 1)
	{
		if (isnum(line) && ((n = ft_atoi(line)) > 0))
			f->ants = n;
		else
			error();
	}
}

t_farm ft_read(int ac, char *av)
{
	t_farm	f;
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = NULL;
	f.fd = (ac == 2) ? open(av, O_RDONLY) : 0;
	ants_num(&f);
	node = rooms(&f, node);
	close(f.fd);
	while (node->next) //ПОЧЕМУ NEXT?????
	{
		printf("name = %s\n", node->name);
		printf("s = %d\n", node->start);
		printf("e = %d\n", node->end);
		node = node->next;
	}
	return (f);
}

int main(int ac, char **av)
{
	t_farm f = ft_read(ac, av[1]);
	ft_printf("fd = %d, rooms = %d, ants = %d\n", f.fd, f.rooms, f.ants);
}