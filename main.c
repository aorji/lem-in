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

#include "lem-in.h"

int isnum(char *s)
{
	if ((ft_atoi(s) != 0 || !ft_strcmp(s, "0")) &&
	(ft_digitsize(ft_atoi(s)) == ft_strlen(s)))
		return (1);
	return (0);
}

void space(char *line)
{
	int i = 0;
	int j = 0;

	while(line[i])
	{
		if (line[i] == ' ')
			j++;
		i++;
	}
	j == 2 ? 0 : exit(1);
}

int	count_rooms(int fd)
{
	char	*line;
	char	**arr;
	int i = 0;

	while (get_next_line(fd, &line) == 1)
	{
		arr = ft_strsplit(line, ' ');
		if ((arrlen(arr) == 3) && isnum(arr[1]) && isnum(arr[2]))
		{
			space(line);
			i++;
		}
		else
			return (i);
	}
	return (i);
}

int ants_num(int fd)
{
	char	*line;
	int n;

	if (get_next_line(fd, &line) == 1)
	{
		if (isnum(line) && (n = ft_atoi(line) > 0))
			return (n);
		exit(1);
	}
	return (-1);
}
t_farm ft_read(int ac, char *av)
{
	t_farm	f;

	f.fd = (ac == 2) ? open(av, O_RDONLY) : 0;
	f.ants = ants_num(f.fd);
	f.rooms = count_rooms(f.fd);
	close(f.fd);
	return (f);
}

void	create_arr(t_farm f, char *av)
{
	// char	**coord;
	// char	**name;
	// char	**links;
	char	***name;
	char	**arr;
	char	*line;
	int		i = -1;
	int		j = -1;
	int fd = 0;

	name = (char ***)malloc(sizeof(char **) * (f.rooms + 1));
	name[f.rooms] = NULL;
	while (++i < f.rooms)
	{
		printf("%s\n", "TUT");
		name[i] = (char **)malloc(sizeof(char *) * (3));
		name[i][3] = NULL;
	}
	i = 0;
	while (name[i])
	{
		j = 0;
		while (name[i][j])
		{
			printf("%s\n", name[i][j]);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_farm f = ft_read(ac, av[1]);
	create_arr(f, av[1]);
	//lemin(ft_read(ac, av[1]));
}