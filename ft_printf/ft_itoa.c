/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:07:45 by aorji             #+#    #+#             */
/*   Updated: 2018/02/04 18:07:48 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len(uintmax_t n, unsigned int b)
{
	int	i;

	i = 1;
	while (n / b)
	{
		n /= b;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(uintmax_t value, unsigned int base)
{
	int			len;
	uintmax_t	n;
	char		*str;

	len = ft_len(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (value >= base)
	{
		n = value;
		value /= base;
		n -= value * base;
		if (n >= 10 && n <= base)
			str[len] = n + 87;
		else
			str[len] = n + 48;
		len--;
	}
	if (value >= 10 && value < base)
		str[len] = (value + 87);
	if (value < 10)
		str[len] = value + 48;
	return (str);
}

char	*ft_itoa_base_up(uintmax_t value, unsigned int base)
{
	int			len;
	uintmax_t	n;
	char		*str;

	len = ft_len(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (value >= base)
	{
		n = value;
		value /= base;
		n -= value * base;
		if (n >= 10 && n <= base)
			str[len] = n + 55;
		else
			str[len] = n + 48;
		len--;
	}
	if (value >= 10 && value < base)
		str[len] = (value + 55);
	if (value < 10)
		str[len] = value + 48;
	return (str);
}

int		ft_digitsize_d(intmax_t n)
{
	int			i;

	i = n < 0 ? 1 : 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_d(intmax_t n)
{
	long long int	nb;
	int				len;
	char			*new;
	int				f;

	f = 0;
	nb = n;
	len = ft_digitsize_d(n);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	new[len--] = '\0';
	if (nb < 0 && (new[0] = '-'))
		nb = -nb;
	if (nb < -9223372036854775807 && (f = 1))
		nb = 223372036854775808;
	while (nb > 9)
	{
		new[len--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	new[len] = (nb + 48);
	f ? new[--len] = 57 : 0;
	return (new);
}
