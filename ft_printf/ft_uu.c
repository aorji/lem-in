/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:23:04 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 11:23:04 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_take_value_u(t_prntf flags, va_list arg)
{
	char	*s;

	if (flags.z)
		s = ft_itoa_base(va_arg(arg, size_t), 10);
	else if (flags.j)
		s = ft_itoa_base(va_arg(arg, intmax_t), 10);
	else if (flags.l == 2)
		s = ft_itoa_base(va_arg(arg, unsigned long long), 10);
	else if (flags.l == 1)
		s = ft_itoa_base(va_arg(arg, unsigned long), 10);
	else if (flags.h == 1)
		s = ft_itoa_base((unsigned short)va_arg(arg, unsigned int), 10);
	else if (flags.h == 2)
		s = ft_itoa_base((unsigned char)va_arg(arg, unsigned int), 10);
	else
		s = ft_itoa_base(va_arg(arg, unsigned int), 10);
	return (s);
}

void		ft_u(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_take_value_u(flags, arg);
	s = ft_use_precision(flags.precision, s);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_strdel(&s);
		return (ft_zero_precision(minus, c));
	}
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}

void		ft_u_up(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_itoa_base(va_arg(arg, unsigned long), 10);
	s = ft_use_precision(flags.precision, s);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_strdel(&s);
		return (ft_zero_precision(minus, c));
	}
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}
