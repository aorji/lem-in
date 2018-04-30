/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:15:54 by aorji             #+#    #+#             */
/*   Updated: 2018/04/30 18:16:05 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>

char **ft_read(int ac, char *av)
{
	char	*line;
	char	**arr;
	int		i = 0;
	int		fd;

	if (ac == 2)
		fd = open(av, O_RDONLY);
	else
		fd = 0;
	while (get_next_line(fd, &line) == 1)
	{
		arr = ft_strsplit(line, ' ');
		if ((arrlen(arr) == 3) && (ft_strlen(arr[1]) == ft_digitsize(ft_atoi(arr[1]))) && (ft_strlen(arr[2]) == ft_digitsize(ft_atoi(arr[2]))))
			i++;
	}
	arr = new_arr(i);
	show_arr(arr);
	return(arr);
}

int main(int ac, char **av)
{
	ft_read(ac, av[1]);
	//lemin(ft_read(ac, av[1]));
}