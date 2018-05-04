/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:22:40 by aorji             #+#    #+#             */
/*   Updated: 2018/02/19 18:22:51 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pos_kod(const char *s)
{
	int j;

	j = 0;
	while (ft_char_coincide(s[j]))
		j++;
	if (j >= (int)ft_strlen(s))
		return (-1);
	else
		return (j);
}

char	*ft_print_full(t_prntf flags, char *c, char *s)
{
	int		minus;
	char	*str;
	char	*tmp;

	minus = ft_check_minus(flags);
	str = ft_strsub(s, 0, (int)ft_strlen(s));
	while (minus - 1 > 0)
	{
		tmp = str;
		str = ft_strjoin(c, str);
		ft_strdel(&tmp);
		minus--;
	}
	if (minus < 0)
	{
		minus = -minus;
		while (minus - 1 > 0)
		{
			tmp = str;
			str = ft_strjoin(str, c);
			ft_strdel(&tmp);
			minus--;
		}
	}
	return (str);
}

char	*ft_full_input(t_prntf flags, char *s)
{
	int		minus;
	char	*c;
	char	*t;

	c = " ";
	minus = ft_check_minus(flags);
	if (minus > 0 && flags.zero)
		c = "0";
	t = ft_print_full(flags, c, s);
	return (t);
}

int		ft_proc_position(const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int		ft_check_midle(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_not_flag(s[i]))
			return (i);
		i++;
	}
	return (-1);
}
