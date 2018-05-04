/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:24:31 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 13:24:33 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_if_printable_uni(char *buf, wchar_t t, char c, t_prntf flags)
{
	int minus;

	minus = ft_check_minus(flags);
	write(1, buf, (int)ft_strlen(buf));
	ft_print_width(minus, ft_count_bytes(t), c);
	g_i += ft_strlen(buf) + ft_count_bytes(t);
	ft_unicode(t);
	ft_print_spaces_srting(minus, ft_count_bytes(t), ' ');
}

static	void	ft_printable_char(char *buf, wchar_t t, char c, t_prntf flags)
{
	int		minus;

	minus = ft_check_minus(flags);
	write(1, buf, (int)ft_strlen(buf));
	ft_print_width(minus, 1, c);
	g_i += ft_strlen(buf) + 1;
	ft_putchar((int)t);
	ft_print_spaces_srting(minus, 1, ' ');
}

void			ft_c(t_prntf flags, va_list arg, char *buf)
{
	wchar_t t;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	if (minus > 0 && flags.zero)
		c = '0';
	t = va_arg(arg, wchar_t);
	if (flags.l)
	{
		if (MB_CUR_MAX == 4)
			ft_if_printable_uni(buf, t, c, flags);
		else
		{
			if (t <= 255)
				ft_if_printable_uni(buf, t, c, flags);
			else
				g_i = -1;
		}
	}
	else
		ft_printable_char(buf, t, c, flags);
}

void			ft_c_up(t_prntf flags, va_list arg, char *buf)
{
	wchar_t	t;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	if (minus > 0 && flags.zero)
		c = '0';
	t = va_arg(arg, wchar_t);
	if (MB_CUR_MAX == 4)
		ft_if_printable_uni(buf, t, c, flags);
	else
	{
		if (t <= 255)
			ft_printable_char(buf, t, c, flags);
		else
			g_i = -1;
	}
}
