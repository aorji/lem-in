/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_an.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:33:45 by aorji             #+#    #+#             */
/*   Updated: 2018/02/19 16:33:46 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_a(void)
{
	write(1, "\n~~~~~~~\n", 9);
	ft_putnbr(g_i);
	write(1, " bytes was printed.\n~~~~~~~\n", 28);
}

void	ft_n(va_list arg)
{
	int *c;

	c = va_arg(arg, int *);
	*c = g_i;
}
