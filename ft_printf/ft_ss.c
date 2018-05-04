/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:36:15 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 13:36:17 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_if_printable(char *buf, t_prntf flags, wchar_t *t, char c)
{
	int	minus;
	int len;

	len = ft_unilen(t);
	if (flags.precision && len > flags.precision)
		len = ft_len_with_precision(t, flags.precision);
	minus = ft_check_minus(flags);
	write(1, buf, (int)ft_strlen(buf));
	ft_print_width(minus, len, c);
	g_i += ft_unicode_s(t, len) + ft_strlen(buf);
	ft_print_spaces_srting(minus, len, c);
}

static	void	ft_check_cur_max(char *buf, t_prntf flags, wchar_t *t, char c)
{
	int len;

	len = ft_unilen(t);
	if (flags.precision && len > flags.precision)
		len = flags.precision;
	if (MB_CUR_MAX == 1)
	{
		if (ft_check_printable(t, len))
			ft_if_printable(buf, flags, t, c);
		else
			g_i = -1;
	}
	else if (MB_CUR_MAX == 4)
		ft_if_printable(buf, flags, t, c);
}

static	void	ft_print_s(t_prntf flags, char c, int len, char *s)
{
	int		minus;
	char	*tmp;

	tmp = ft_strsub(s, 0, len);
	minus = ft_check_minus(flags);
	ft_print_width(minus, len, c);
	write(1, s, len);
	g_i += len;
	ft_print_spaces_srting(minus, len, c);
	ft_strdel(&tmp);
}

void			ft_s(t_prntf flags, va_list arg, char *buf)
{
	void	*s;
	char	c;
	int		minus;
	int		f;

	c = ' ';
	f = 0;
	s = va_arg(arg, wchar_t *);
	(flags.up || flags.down) ? ft_ul_case(&s, flags) : 0;
	minus = ft_check_minus(flags);
	(minus > 0 && flags.zero) ? c = '0' : 0;
	if (!flags.precision && flags.point)
		return (ft_zero_precision_s(minus, c, buf));
	if (!s && (f = 1))
		s = "(null)";
	(flags.l && !f) ? ft_check_cur_max(buf, flags, s, c) : 0;
	if (!(flags.l && !f))
	{
		write(1, buf, (minus = (int)ft_strlen(buf)));
		g_i += minus;
		if (flags.point && flags.precision < (int)ft_strlen(s))
			ft_print_s(flags, c, flags.precision, s);
		else
			ft_print_s(flags, c, (int)ft_strlen(s), s);
	}
}

void			ft_s_up(t_prntf flags, va_list arg, char *buf)
{
	wchar_t	*t_s;
	int		minus;
	char	c;

	t_s = va_arg(arg, wchar_t *);
	c = ' ';
	minus = ft_check_minus(flags);
	if (minus > 0 && flags.zero)
		c = '0';
	if (!flags.precision && flags.point)
		return (ft_zero_precision_s(minus, c, buf));
	if (!t_s)
	{
		ft_print_width(minus, 6, c);
		write(1, buf, (int)ft_strlen(buf));
		write(1, "(null)", 6);
		g_i = 6 + ft_strlen(buf);
		return ;
	}
	ft_check_cur_max(buf, flags, t_s, c);
}
