/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:43:23 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/03 15:28:07 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

void	ft_help(t_line *line, t_window *wind)
{
	while (line->x1 != line->x2 || line->y1 != line->y2)
	{
		mlx_pixel_put(wind->mlx, wind->win, line->x1, line->y1, line->color);
		line->error2 = line->error * 2;
		if (line->error2 > -(line->deltay))
		{
			line->error -= line->deltay;
			line->x1 += line->signx;
		}
		if (line->error2 < line->deltax)
		{
			line->error += line->deltax;
			line->y1 += line->signy;
		}
	}
}

void	ft_line(t_pix *a, t_pix *b, t_window *wind)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	line->x1 = a->x;
	line->y1 = a->y;
	line->x2 = b->x;
	line->y2 = b->y;
	if (b->z > a->z)
		line->color = b->c;
	else
		line->color = a->c;
	line->deltax = abs(line->x2 - line->x1);
	line->deltay = abs(line->y2 - line->y1);
	if (line->x1 < line->x2)
		line->signx = 1;
	else
		line->signx = -1;
	if (line->y1 < line->y2)
		line->signy = 1;
	else
		line->signy = -1;
	line->error = line->deltax - line->deltay;
	mlx_pixel_put(wind->mlx, wind->win, line->x2, line->y2, line->color);
	ft_help(line, wind);
}
