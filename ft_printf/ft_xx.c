/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:35:18 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 10:35:19 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_take_value_x(t_prntf flags, va_list arg)
{
	char	*s;

	if (flags.z)
		s = ft_itoa_base(va_arg(arg, size_t), 16);
	else if (flags.j)
		s = ft_itoa_base(va_arg(arg, intmax_t), 16);
	else if (flags.l == 2)
		s = ft_itoa_base(va_arg(arg, unsigned long long), 16);
	else if (flags.l == 1)
		s = ft_itoa_base(va_arg(arg, unsigned long), 16);
	else if (flags.h == 1)
		s = ft_itoa_base((unsigned short)va_arg(arg, unsigned int), 16);
	else if (flags.h == 2)
		s = ft_itoa_base((unsigned char)va_arg(arg, unsigned int), 16);
	else
		s = ft_itoa_base(va_arg(arg, unsigned int), 16);
	return (s);
}

static char	*ft_take_value_x_up(t_prntf flags, va_list arg)
{
	char	*s;

	if (flags.z)
		s = ft_itoa_base_up(va_arg(arg, size_t), 16);
	else if (flags.j)
		s = ft_itoa_base_up(va_arg(arg, intmax_t), 16);
	else if (flags.l == 2)
		s = ft_itoa_base_up(va_arg(arg, unsigned long long), 16);
	else if (flags.l == 1)
		s = ft_itoa_base_up(va_arg(arg, unsigned long), 16);
	else if (flags.h == 1)
		s = ft_itoa_base_up((unsigned short)va_arg(arg, unsigned int), 16);
	else if (flags.h == 2)
		s = ft_itoa_base_up((unsigned char)va_arg(arg, unsigned int), 16);
	else
		s = ft_itoa_base_up(va_arg(arg, unsigned int), 16);
	return (s);
}

void		ft_x(t_prntf flags, va_list arg)
{
	char	*s;
	char	c;
	int		minus;
	char	*tmp;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_take_value_x(flags, arg);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	s = ft_use_precision(flags.precision, s);
	if (flags.sharp && ft_atoi(s) != 0)
	{
		tmp = s;
		s = ft_strjoin("0x", s);
		ft_strdel(&tmp);
	}
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_strdel(&s);
		return (ft_zero_precision(minus, c));
	}
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}

void		ft_x_up(t_prntf flags, va_list arg)
{
	char	*s;
	char	c;
	int		minus;
	char	*tmp;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_take_value_x_up(flags, arg);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	s = ft_use_precision(flags.precision, s);
	if (flags.sharp && ft_atoi(s) != 0)
	{
		tmp = s;
		s = ft_strjoin("0X", s);
		ft_strdel(&tmp);
	}
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_strdel(&s);
		return (ft_zero_precision(minus, c));
	}
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}
