/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:18:44 by aorji             #+#    #+#             */
/*   Updated: 2018/02/08 15:18:46 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_return(char **buf)
{
	g_i += ft_strlen(*buf);
	write(1, *buf, (int)ft_strlen(*buf));
	ft_strdel(buf);
	return (g_i);
}

int			ft_char_coincide(char c)
{
	if (c != 's' && c != 'S' && c != 'c' && c != 'C' && c != 'x' && c != 'X'
		&& c != 'p' && c != 'd' && c != 'i' && c != 'o' && c != 'O' && c != 'u'
		&& c != 'U' && c != '%' && c != 'D' && c != '@' && c != 'n'
		&& c != 'b')
		return (1);
	return (0);
}

static int	ft_main_code(char **buf, va_list arg, const char **format, int j)
{
	char	*flag_str;

	flag_str = ft_strsub(*format, 0, j);
	ft_print(arg, *buf, ft_fillflags(flag_str), (*format)[j]);
	ft_strdel(buf);
	ft_strdel(&flag_str);
	if (g_i == -1)
	{
		ft_strdel(buf);
		return (-1);
	}
	*format += j + 1;
	return (1);
}

static int	ft_del(char **buf)
{
	ft_strdel(buf);
	return (g_i);
}

int			ft_printf(const char *format, ...)
{
	int		a;
	int		j;
	int		u;
	char	*buf;
	va_list arg;

	a = 0;
	u = 1;
	g_i = 0;
	va_start(arg, format);
	while (*format)
	{
		if ((a = ft_buf(&format, &buf)) >= 0)
			return (a);
		if ((a = ft_positon(&a, &j, &format)) != -1)
			return (ft_del(&buf));
		if ((u = ft_add_buf(a, j, &buf, &format)) <= 0)
			return (ft_return(&buf));
		(*format == '%' && u == 0) ? (format++) : 0;
		while (ft_char_coincide(format[j]))
			j++;
		if ((a = ft_main_code(&buf, arg, &format, j)) != 1)
			return (a);
	}
	return (g_i);
}
