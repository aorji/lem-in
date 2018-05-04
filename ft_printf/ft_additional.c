/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:46:24 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 16:46:26 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_printable(wchar_t *t, int len)
{
	int i;

	i = 0;
	while (len)
	{
		if (t[i] > 255)
			return (0);
		len--;
	}
	return (1);
}

void	ft_b(t_prntf flags)
{
	if (flags.width)
		write(1, CYAN, (int)ft_strlen(CYAN));
	else
		write(1, RESET, (int)ft_strlen(RESET));
}

void	ft_ul_case(void **str, t_prntf flags)
{
	int		i;
	char	*s;

	i = -1;
	s = ft_strnew(ft_strlen((char *)str));
	s = ft_strcpy(s, *str);
	if (flags.up && !flags.down)
	{
		while (s[++i])
		{
			if (s[i] >= 97 && s[i] <= 122)
				s[i] = s[i] - 32;
		}
	}
	if (flags.down && !flags.up)
	{
		while (s[++i])
		{
			if (s[i] >= 65 && s[i] <= 90)
				s[i] = s[i] + 32;
		}
	}
	*str = (void *)s;
	ft_strdel(&s);
}
