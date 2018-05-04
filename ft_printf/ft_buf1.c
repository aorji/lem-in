/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:56:36 by aorji             #+#    #+#             */
/*   Updated: 2018/02/19 20:56:37 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_buf(const char **format, char **buf)
{
	char	*tmp;
	char	*sub;

	*buf = ft_strnew(1);
	while (**format != '%' && **format)
	{
		tmp = *buf;
		sub = ft_strsub(*format, 0, 1);
		*buf = ft_strjoin(*buf, sub);
		ft_strdel(&sub);
		ft_strdel(&tmp);
		(*format)++;
	}
	if (**format == '%' && ft_strlen(*format) == 1)
	{
		ft_strdel(buf);
		return (0);
	}
	if (!**format)
		return (ft_return(buf));
	if (**format == '%')
		(*format)++;
	return (-1);
}

static int	ft_if(char **buf, const char **format, int a)
{
	char	*tmp;
	char	*tmp1;
	char	*str;
	t_prntf	flags;
	int		i;

	i = 0;
	tmp = ft_strsub(*format, 0, a + 1);
	flags = ft_fillflags(tmp);
	while (!ft_not_flag(tmp[i]))
		i++;
	str = ft_strsub(tmp, i, ((int)ft_strlen(tmp) - i));
	ft_strdel(&tmp);
	tmp = ft_full_input(flags, str);
	ft_strdel(&str);
	tmp1 = *buf;
	*buf = ft_strjoin(*buf, tmp);
	ft_strdel(&tmp1);
	ft_strdel(&tmp);
	*format += a + 1;
	if (!**format)
		return (-1);
	return (1);
}

int			ft_add_buf(int a, int j, char **buf, const char **format)
{
	char	*tmp;
	int		u;
	char	*sub;

	sub = ft_strsub(*format, 0, j);
	if ((u = 1) && (ft_check_midle(sub) >= 0))
	{
		while (j && !(u = 0))
		{
			tmp = ft_strsub(*format, 0, j);
			a = ft_check_midle(tmp);
			ft_strdel(&tmp);
			if (a >= 0)
			{
				if ((a = ft_if(buf, format, a)) == -1)
				{
					ft_strdel(&sub);
					return (a);
				}
			}
			j--;
		}
	}
	ft_strdel(&sub);
	return (u);
}

int			ft_positon(int *a, int *j, const char **format)
{
	*j = ft_proc_position(*format);
	*a = ft_pos_kod(*format);
	if (*a >= 0 && *j > *a)
		*j = *a;
	if (*j < 0)
		return (g_i);
	else
		return (-1);
}

int			ft_not_flag(char c)
{
	if (c != 'h' && c != 'l' && c != 'j' && c != 'z' && c != '#' && c != '0'
		&& c != '-' && c != '+' && c != ' ' && c != '%' && c != '.'
		&& !(c >= 48 && c <= 57) && c != 's' && c != 'S' && c != 'c' && c != 'C'
		&& c != 'x' && c != 'X' && c != 'p' && c != 'd' && c != 'i' && c != 'o'
		&& c != 'O' && c != 'u' && c != 'U' && c != '%' && c != 'D' && c != '-'
		&& c != '+' && c != '@' && c != 'n' && c != 'b' && c != '^' && c != '_')
		return (1);
	return (0);
}
