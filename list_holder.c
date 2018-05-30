/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_holder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:41:14 by aorji             #+#    #+#             */
/*   Updated: 2018/05/30 18:41:15 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_holder	*new_holder(void)
{
	t_holder	*new;

	new = (t_holder *)malloc(sizeof(t_holder));
	new->next = NULL;
	return (new);
}

void		fill_holder(t_holder **lh, t_list **list)
{
	(*lh)->lst = (*list);
	(*lh)->res = (*list);
	(*lh)->next = new_holder();
	(*lh) = (*lh)->next;
}
