/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:06:07 by aorji             #+#    #+#             */
/*   Updated: 2018/05/04 18:06:08 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arrdel(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		i++;
	}
	free(arr);
	arr = NULL;
	return (1);
}
