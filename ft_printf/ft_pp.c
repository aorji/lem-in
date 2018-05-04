/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:31:24 by aorji             #+#    #+#             */
/*   Updated: 2018/02/16 13:31:26 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p(t_prntf flags, va_list arg)
{
	char	*s;
	int		minus;
	char	c;
	char	*tmp;

	c = ' ';
	minus = ft_check_minus(flags);
	if (minus > 0 && flags.zero)
		c = '0';
	s = ft_itoa_base(va_arg(arg, uintmax_t), 16);
	if (!flags.precision && flags.point && ft_atoi(s) == 0)
	{
		ft_putstr("0x");
		g_i += 2;
		return ;
	}
	s = ft_use_precision(flags.precision, s);
	tmp = s;
	s = ft_strjoin("0x", s);
	ft_strdel(&tmp);
	g_i += ft_strlen(s);
	ft_print_spaces(minus, (int)ft_strlen(s), s, c);
	ft_strdel(&s);
}

void	ft_proc(t_prntf flags)
{
	int		minus;
	char	c;

	c = ' ';
	g_i++;
	minus = ft_check_minus(flags);
	if (minus > 0 && flags.zero)
		c = '0';
	ft_print_spaces(minus, 1, "%", c);
}
