/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:27:39 by aorji             #+#    #+#             */
/*   Updated: 2017/11/07 21:27:41 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t lens1;

	lens1 = ft_strlen(s1);
	while (*s2)
	{
		s1[lens1] = *s2++;
		lens1++;
	}
	s1[lens1] = '\0';
	return (s1);
}
