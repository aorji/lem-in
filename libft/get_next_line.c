/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:40:45 by aorji             #+#    #+#             */
/*   Updated: 2018/01/09 16:40:49 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_if_newline(t_gnl **list, char **line, int i)
{
	char	*tmp;

	if ((*list)->content[i] == '\n')
	{
		*line = ft_strsub((*list)->content, 0, i);
		tmp = (*list)->content;
		(*list)->content = ft_strsub((*list)->content, i + 1,
			ft_strlen((*list)->content) - i);
		free(tmp);
		return (1);
	}
	return (0);
}

static int			ft_gnl_rest(t_gnl **list, char **line)
{
	int	i;

	i = 0;
	while ((*list)->content[i] != '\n' && (*list)->content[i])
		i++;
	if (ft_if_newline(list, line, i))
		return (1);
	else
	{
		*line = (*list)->content;
		(*list)->content = NULL;
		return (1);
	}
}

static int			ft_read(int fd, char **line, t_gnl **list)
{
	int		i;
	char	*buf;
	char	*tmp;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		i = 0;
		tmp = (*list)->content;
		(*list)->content = ft_strjoin((*list)->content, buf);
		free(tmp);
		while ((*list)->content[i] != '\n' && (*list)->content[i])
			i++;
		if (ft_if_newline(list, line, i))
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	if (i == -1 || (i = ft_strlen((*list)->content)) == 0)
		return (i);
	return (ft_gnl_rest(list, line));
}

static	t_list		*ft_llstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = (void *)malloc(sizeof(void) * content_size);
	if (!new->content)
		return (0);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ft_bzero(new->content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	t_gnl			*list;
	static	t_gnl	*head;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!head)
		head = (t_gnl *)ft_llstnew("", fd);
	list = head;
	while (list->fd != fd && list->next)
		list = list->next;
	if (list->fd != fd)
	{
		list->next = (t_gnl *)ft_llstnew("", fd);
		list = list->next;
	}
	if (!list->content)
		return (0);
	i = ft_read(fd, line, &list);
	return (i);
}
