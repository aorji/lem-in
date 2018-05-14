/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:26:57 by aorji             #+#    #+#             */
/*   Updated: 2018/05/14 21:26:58 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*create_way(t_node *s, t_node *e, t_node *node)
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

t_node	*previous(t_node *head, char *name)
{
	while (ft_strcmp(head->name, name))
		head = head->next;
	return (head);
}

void	print_way(t_list *list)
{
	if (list->next)
	{
		print_way(list->next);
		printf("[%s]->", list->content);
	}
}