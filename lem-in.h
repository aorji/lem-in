/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:05:51 by aorji             #+#    #+#             */
/*   Updated: 2018/05/01 13:05:55 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef	struct		s_farm
{
	int				ants;
	int				rooms;
	int				fd;
}					t_farm;

typedef	struct		s_map
{
	char			**arr;
}					t_map;
