/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:37:08 by aorji             #+#    #+#             */
/*   Updated: 2018/02/15 21:37:09 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_use_precision(int prec, char *s)
{
	int		minus;
	char	*leak;

	minus = 1;
	while (prec > (int)ft_strlen(s))
	{
		if (ft_atoi(s) < 0)
		{
			leak = s;
			s = ft_strsub(s, 1, ft_strlen(s) - 1);
			ft_strdel(&leak);
			minus = -1;
		}
		leak = s;
		s = ft_strjoin("0", s);
		ft_strdel(&leak);
	}
	if (minus == -1)
	{
		leak = s;
		s = ft_strjoin("-", s);
		ft_strdel(&leak);
	}
	return (s);
}

void	ft_zero_precision(int minus, char c)
{
	if (minus > 0)
		ft_print_width(minus, 0, c);
}

void	ft_zero_precision_s(int minus, char c, char *buf)
{
	write(1, buf, (int)ft_strlen(buf));
	g_i += ft_strlen(buf);
	if (minus > 0)
		ft_print_width(minus, 0, c);
}

int		ft_len_with_precision(wchar_t *value, int unilen)
{
	int	i;
	int	start;

	i = 0;
	start = unilen;
	while (unilen > 0)
	{
		if ((unilen - ft_count_bytes(value[i])) >= 0)
		{
			unilen -= ft_count_bytes(value[i]);
			i++;
		}
		else
			return (start - unilen);
	}
	return (start - unilen);
}
