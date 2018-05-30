/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_find_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:09:33 by aorji             #+#    #+#             */
/*   Updated: 2018/05/30 19:09:34 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*create_current(t_node *tmp, t_node *current)
{
	tmp->step = current->step + 1;
	tmp->kid = tmp->reserve;
	tmp->previous = current->name;
	return (tmp);
}

t_node	*next_kid(t_node *current)
{
	current->kid = current->kid->next;
	return (current);
}

t_node	*search_next(t_node *tmp, t_node *current)
{
	tmp->step = current->step + 1;
	tmp->previous = current->name;
	return (tmp);
}
