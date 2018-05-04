/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:34:33 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 10:34:34 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_take_value_di(t_prntf flags, va_list arg)
{
	char	*s;

	if (flags.z)
		s = ft_itoa_d(va_arg(arg, size_t));
	else if (flags.j)
		s = ft_itoa_d(va_arg(arg, intmax_t));
	else if (flags.l == 2)
		s = ft_itoa_d(va_arg(arg, long long));
	else if (flags.l == 1)
		s = ft_itoa_d(va_arg(arg, long));
	else if (flags.h == 1)
		s = ft_itoa_d((short)va_arg(arg, int));
	else if (flags.h == 2)
		s = ft_itoa_d((char)va_arg(arg, int));
	else
		s = ft_itoa_d(va_arg(arg, int));
	return (s);
}

char		*ft_pluse_space(char *s, t_prntf flags)
{
	char *tmp;

	if (flags.pluse)
	{
		tmp = s;
		s = ft_strjoin("+", s);
		ft_strdel(&tmp);
	}
	else if (flags.space)
	{
		tmp = s;
		s = ft_strjoin(" ", s);
		ft_strdel(&tmp);
	}
	return (s);
}

void		ft_di(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_take_value_di(flags, arg);
	s = ft_use_precision(flags.precision, s);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_strdel(&s);
		return (ft_zero_precision(minus, c));
	}
	if ((flags.space || flags.pluse) && ft_atoi(s) >= 0)
		s = ft_pluse_space(s, flags);
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}

void		ft_d_up(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_itoa_d(va_arg(arg, long));
	s = ft_use_precision(flags.precision, s);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_strdel(&s);
		return (ft_zero_precision(minus, c));
	}
	if ((flags.space || flags.pluse) && ft_atoi(s) >= 0)
		s = ft_pluse_space(s, flags);
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}
