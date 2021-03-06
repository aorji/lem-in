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

char		**new_arr(int n, int m)
{
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	map[n] = NULL;
	while (n)
	{
		map[n - 1] = (char *)malloc(sizeof(char) * (m + 1));
		ft_memset(map[n - 1], 48, m);
		map[n - 1][m] = '\0';
		n--;
	}
	return (map);
}
