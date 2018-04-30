/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 19:15:20 by aorji             #+#    #+#             */
/*   Updated: 2018/04/30 19:15:43 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**new_arr(int size)
{
	char	**map;
	int		n;

	n = size;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	while (n)
	{
		map[n - 1] = (char *)malloc(sizeof(char) * (size + 1));
		ft_memset(map[n - 1], 48, size);
		map[n - 1][size] = '\0';
		n--;
	}
	return (map);
}
