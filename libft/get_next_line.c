/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:34:57 by sandruse          #+#    #+#             */
/*   Updated: 2017/02/04 09:51:47 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		look_for_n(char **line, char **copy)
{
	int			i;
	char		*tofree;

	i = -1;
	while (copy[0][++i])
		if (copy[0][i] == '\n')
		{
			tofree = *copy;
			*line = ft_strsub(copy[0], 0, i);
			*copy = ft_strsub(copy[0], i + 1, (ft_strlen(copy[0]) - i - 1));
			free(tofree);
			return (1);
		}
	*line = ft_strsub(*copy, 0, ft_strlen(*copy));
	ft_strdel(&*copy);
	if (*line[0] != '\0')
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tofree;
	static char	*copy[4096];

	if (fd < 0 || !line || fd > 4096)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret >= 0)
	{
		buf[ret] = '\0';
		tofree = copy[fd];
		if (!copy[fd])
			copy[fd] = ft_strdup(buf);
		else
			copy[fd] = ft_strjoin(copy[fd], buf);
		free(tofree);
	}
	if (copy[fd] == NULL && ret < 0)
		return (-1);
	else if (copy[fd] == NULL)
		return (0);
	return (look_for_n(&*line, &copy[fd]));
}
