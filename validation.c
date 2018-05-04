/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:56:42 by aorji             #+#    #+#             */
/*   Updated: 2018/05/04 17:56:44 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		isnum(char *s)
{
	if ((ft_atoi(s) != 0 || !ft_strcmp(s, "0")) &&
	(ft_digitsize(ft_atoi(s)) == ft_strlen(s)))
		return (1);
	return (0);
}

void	check_spaces(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			j++;
		i++;
	}
	j == 2 ? 0 : error();
}
