/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:20:24 by aorji             #+#    #+#             */
/*   Updated: 2018/02/04 18:20:27 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unilen(wchar_t *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i += ft_count_bytes(*s);
		s++;
	}
	return (i);
}

int	ft_count_bytes(wchar_t value)
{
	if (value <= 127)
		return (1);
	else if (value <= 2047)
		return (2);
	else if (value <= 65535)
		return (3);
	else
		return (4);
}

int	ft_unicode(wchar_t value)
{
	int	len;

	len = ft_count_bytes(value);
	if (len == 1)
		ft_putchar(value);
	else if (len == 2)
	{
		ft_putchar((value >> 6) | 0xC0);
		ft_putchar((value & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		ft_putchar((value >> 12) | 0xE0);
		ft_putchar(((value >> 6) & 0x3F) | 0x80);
		ft_putchar((value & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		ft_putchar((value >> 18) | 0xF0);
		ft_putchar(((value >> 12) & 0x3F) | 0x80);
		ft_putchar(((value >> 6) & 0x3F) | 0x80);
		ft_putchar((value & 0x3F) | 0x80);
	}
	return (len);
}

int	ft_unicode_s(wchar_t *value, int unilen)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (unilen > 0)
	{
		if ((unilen - ft_count_bytes(value[i])) >= 0)
		{
			len += ft_unicode(value[i]);
			unilen -= ft_count_bytes(value[i]);
			i++;
		}
		else
			return (len);
	}
	return (len);
}
