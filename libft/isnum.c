/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:23:56 by aorji             #+#    #+#             */
/*   Updated: 2018/05/22 19:23:57 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isnum(char *s)
{
	if ((ft_atoi(s) != 0 || !ft_strcmp(s, "0")) &&
	(ft_digitsize(ft_atoi(s)) == (int)ft_strlen(s)))
		return (1);
	return (0);
}
