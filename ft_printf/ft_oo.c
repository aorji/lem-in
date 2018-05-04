/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:45:02 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 10:45:03 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_take_value_o(t_prntf flags, va_list arg)
{
	char	*s;

	if (flags.z)
		s = ft_itoa_base(va_arg(arg, size_t), 8);
	else if (flags.j)
		s = ft_itoa_base(va_arg(arg, intmax_t), 8);
	else if (flags.l == 2)
		s = ft_itoa_base(va_arg(arg, unsigned long long), 8);
	else if (flags.l == 1)
		s = ft_itoa_base(va_arg(arg, unsigned long), 8);
	else if (flags.h == 1)
		s = ft_itoa_base((unsigned short)va_arg(arg, unsigned int), 8);
	else if (flags.h == 2)
		s = ft_itoa_base((unsigned char)va_arg(arg, unsigned int), 8);
	else
		s = ft_itoa_base(va_arg(arg, unsigned int), 8);
	return (s);
}

static char	*ft_sharp(t_prntf flags, char *s)
{
	char	*tmp;

	if (flags.sharp && ft_atoi(s) != 0)
	{
		tmp = s;
		s = ft_strjoin("0", s);
		ft_strdel(&tmp);
	}
	return (s);
}

void		ft_o(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_take_value_o(flags, arg);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	s = ft_sharp(flags, s);
	s = ft_use_precision(flags.precision, s);
	if (flags.precision == 0 && flags.point == 1 && ft_atoi(s) == 0)
	{
		ft_zero_precision(minus, c);
		if (flags.sharp)
		{
			write(1, "0", 1);
			g_i++;
		}
		ft_strdel(&s);
		return ;
	}
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}

void		ft_o_up(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;

	c = ' ';
	minus = ft_check_minus(flags);
	s = ft_itoa_base_up(va_arg(arg, uintmax_t), 8);
	if (minus > 0 && flags.zero && (!flags.precision || ft_atoi(s) < 0))
		c = '0';
	s = ft_sharp(flags, s);
	s = ft_use_precision(flags.precision, s);
	if (flags.precision == 0 && flags.point == 1 && ft_atoi(s) == 0)
	{
		ft_zero_precision(minus, c);
		if (flags.sharp)
		{
			write(1, "0", 1);
			g_i++;
		}
		ft_strdel(&s);
		return ;
	}
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	g_i += ft_strlen(s);
	ft_strdel(&s);
}
