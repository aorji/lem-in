/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:20:14 by aorji             #+#    #+#             */
/*   Updated: 2018/02/08 18:20:17 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(va_list arg, char *buf, t_prntf flags, char kod)
{
	if (ft_sc(arg, buf, flags, kod))
		return ;
	write(1, buf, (int)ft_strlen(buf));
	g_i += ft_strlen(buf);
	kod == 'X' ? ft_x_up(flags, arg) : 0;
	kod == 'x' ? ft_x(flags, arg) : 0;
	(kod == 'd' || kod == 'i') ? ft_di(flags, arg) : 0;
	kod == 'D' ? ft_d_up(flags, arg) : 0;
	kod == 'o' ? ft_o(flags, arg) : 0;
	kod == 'O' ? ft_o_up(flags, arg) : 0;
	kod == 'p' ? ft_p(flags, arg) : 0;
	kod == '%' ? ft_proc(flags) : 0;
	kod == 'u' ? ft_u(flags, arg) : 0;
	kod == 'U' ? ft_u_up(flags, arg) : 0;
	kod == 'n' ? ft_n(arg) : 0;
	kod == '@' ? ft_a() : 0;
	kod == 'b' ? ft_b(flags) : 0;
}

int		ft_sc(va_list arg, char *buf, t_prntf flags, char kod)
{
	int i;

	i = 0;
	if (kod == 'S' || kod == 's' || kod == 'C' || kod == 'c')
	{
		if (kod == 'S')
			ft_s_up(flags, arg, buf);
		if (kod == 'c')
			ft_c(flags, arg, buf);
		if (kod == 's')
			ft_s(flags, arg, buf);
		if (kod == 'C')
			ft_c_up(flags, arg, buf);
		i = 1;
	}
	return (i);
}

int		ft_check_minus(t_prntf flags)
{
	int	i;

	i = 0;
	if (flags.minus == 1 && flags.width)
		i = flags.width * (-1);
	if (flags.minus == 0 && flags.width)
		i = flags.width;
	return (i);
}
