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

static void	print_way(t_list *list)
{
	if (list->next)
	{
		print_way(list->next);
		printf("[%s]->", list->content);
	}
}

static t_list	*create_way(t_node *s, t_node *e, t_node *node)
{
	t_node	*head;
	t_list	*list;
	t_list	*head_l;

	head = node;
	if (!(e->previous))
		return(NULL);
	list = ft_lstnew(NULL, 0);
	head_l = list;
	list->content = e->name;
	list->next = ft_lstnew(NULL, 0);
	list = list->next;
	while (ft_strcmp(e->name, s->name))
	{
		list->content = e->previous;
		list->next = ft_lstnew(NULL, 0);
		list = list->next;
		e = previous(head, e->previous);
	}
	return (head_l);
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

static void ft_reset(t_node **reset, t_node *node)
{
	*reset = node;
	while (node->next)
	{
		node->step = 0;
		node->previous = NULL;
		node->kid = node->reserve;
		node = node->next;
	}
}

static t_node *del(t_node *node, t_list *list, t_node *s, t_node *e)
{
	t_list	*head;
	t_node	*tmp;
	t_node	*new;
	
	head = list;
	while (list->next)
	{
		if (!ft_strcmp(node->name, list->content) && ft_strcmp(node->name, s->name) && ft_strcmp(node->name, e->name))
		{
			tmp = node;
			node = node->next;
			free(tmp);
			list = head;
		}
		list = list->next;
	}
	new = node;
	while (node->next && node->next->next)
	{
		list = head;
		while (list->next)
		{
			if (!ft_strcmp(node->next->name, list->content) && ft_strcmp(node->next->name, s->name) && ft_strcmp(node->next->name, e->name))
			{
				tmp = node->next;
				node->next = node->next->next;
				free(tmp);
			}
			else
				list = list->next;
		}
		node = node->next;
	}
	return (new);
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
	e = end(node);
	s = start(node);
	node = create_reserve(node);
	while (f.ants)
	{
		find_way(&node, s);
		list = create_way(s, e, node);
		print_way(list);
		printf("done\n");
		ft_reset(&reset, node);
		node = reset; 
		node = del(node, list, s, e);
		find_way(&node, s);
		list = create_way(s, e, node);
		print_way(list);
		printf("done\n");
		break ;
		f.ants--;
	}	
	return (1);
}
