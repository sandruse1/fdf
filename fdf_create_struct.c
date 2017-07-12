/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:11:23 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/11 12:15:06 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		fdf_set_z_and_color(t_pix **pixel, char **str, int i)
{
	if (i == 1)
	{
		(*pixel)->z = ft_atoi(str[0]);
		(*pixel)->c = ft_atoi_base(str[1] + 2, 16);
	}
	else
	{
		(*pixel)->z = ft_atoi(str[0]);
		if ((ft_atoi(str[0])) < 0)
			(*pixel)->c = ft_atoi_base("00FF00", 16);
		else if (ft_atoi(str[0]) > 0)
			(*pixel)->c = ft_atoi_base("FF0000", 16);
		else
			(*pixel)->c = ft_atoi_base("FFFFFF", 16);
	}
}

void		free_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void		free_pix(t_pix **pixel)
{
	t_pix	*tmp;
	t_pix	*last;

	tmp = *pixel;
	while (tmp->n)
	{
		last = tmp;
		tmp = tmp->n;
	}
	free(tmp);
	last->n = NULL;
}

t_pix		*fdf_setcord_color(char *line, t_pix *pixel, int y, t_len **len)
{
	char		**str_x;
	char		**str_color;
	int			i;

	i = 0;
	str_x = ft_strsplit(line, ' ');
	while (str_x[i])
	{
		pixel->y0 = y;
		pixel->y = y;
		pixel->x0 = i;
		pixel->x = i;
		str_color = ft_strsplit(str_x[i++], ',');
		if (str_color[1])
			fdf_set_z_and_color(&pixel, str_color, 1);
		else
			fdf_set_z_and_color(&pixel, str_color, 0);
		if (!(pixel->n = (t_pix*)malloc(sizeof(t_pix))))
			return (NULL);
		pixel = pixel->n;
	}
	ft_valid_len(i, len);
	free_array(str_x);
	free_array(str_color);
	return (pixel);
}

t_pix		*fdf_create_struct(int fd)
{
	t_pix		*pixel;
	t_pix		*tmp;
	t_len		*len;
	int			y;
	char		*line;

	if (!(pixel = (t_pix*)malloc(sizeof(t_pix))))
		return (NULL);
	if (!(len = (t_len*)malloc(sizeof(t_len))))
		return (NULL);
	tmp = pixel;
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_valid_file(line);
		tmp = fdf_setcord_color(line, tmp, y++, &len);
		if (!(tmp->n = (t_pix*)malloc(sizeof(t_pix))))
			return (NULL);
		free(line);
	}
	tmp->n = NULL;
	free_pix(&pixel);
	if (close(fd) == -1)
		fdf_error(3);
	return (pixel);
}
