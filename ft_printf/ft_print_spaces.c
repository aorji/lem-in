/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:30:20 by aorji             #+#    #+#             */
/*   Updated: 2018/02/13 21:30:22 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_skip_symbols(char *s)
{
	while (*s == '+' || *s == '-' || *s == ' ')
	{
		write(1, &*s, 1);
		s++;
	}
	if (*s == 48 && *(s + 1) == 'x')
	{
		write(1, "0x", 2);
		s += 2;
	}
	return (s);
}

void			ft_print_width(int minus, int len, char c)
{
	int	i;

	if ((minus - len) >= 0)
	{
		i = minus - len;
		while (i)
		{
			write(1, &c, 1);
			i--;
			g_i++;
		}
	}
}

void			ft_print_spaces(int minus, int len, char *s, char c)
{
	int	check;
	int i;

	check = 0;
	if (minus > 0 && c == '0')
		s = ft_skip_symbols(s);
	if (minus < 0)
	{
		write(1, s, (int)ft_strlen(s));
		minus = -minus;
		check = 1;
	}
	if ((minus - len) >= 0)
	{
		i = minus - len;
		while (i)
		{
			write(1, &c, 1);
			g_i++;
			i--;
		}
	}
	if (!check)
		write(1, s, (int)ft_strlen(s));
}

void			ft_print_spaces_srting(int minus, int len, char c)
{
	minus = -minus;
	ft_print_width(minus, len, c);
}
