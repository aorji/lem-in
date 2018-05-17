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

#include "lemin.h"

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

void	check_dash(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line == '-')
			i++;
		line++;
	}
	if (i > 1)
		error();
}

int		check_elem(char *a, char *b, char *c)
{
	if (isnum(b) && isnum(c) && a[0] != 'L' && a[0] != '#')
		return (1);
	error();
	return (0);
}
