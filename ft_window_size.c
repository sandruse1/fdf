/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:17:21 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/11 12:53:22 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

void	ft_window_size(t_window **wind, t_pix **p)
{
	t_pix	*tmp;
	int		x;
	int		y;

	tmp = *p;
	while (tmp->n)
		tmp = tmp->n;
	x = tmp->x;
	y = tmp->y;
	(*wind)->krok = 1900 / (x + y);
	if ((*wind)->krok < 2)
		(*wind)->krok = 1;
	(*wind)->vidx = y * (*wind)->krok;
	(*wind)->vidy = 100;
	if ((*wind)->krok == 1)
		(*wind)->vidx = (*wind)->vidx * 2;
}

void	ft_zaholovok(t_window *wind)
{
	char	**name;
	char	*s;

	s = ft_strdup("MAP : ");
	name = ft_strsplit(wind->name, '.');
	s = ft_strjoin(s, name[0]);
	mlx_string_put(wind->mlx, wind->win, 900, 5, 0xFFF800, s);
	mlx_string_put(wind->mlx, wind->win, 5, 3, 0x00FF00, "Zoom + : NUM +");
	mlx_string_put(wind->mlx, wind->win, 5, 23, 0x00FF00, "Zoom - : NUM -");
	mlx_string_put(wind->mlx, wind->win, 5, 43, 0x00FF00,
			"Move   : by arrows");
	mlx_string_put(wind->mlx, wind->win, 5, 63, 0x00FF00,
			"Close window : Esc");
	mlx_string_put(wind->mlx, wind->win, 5, 83, 0x00FF00,
			"Height + : +");
	mlx_string_put(wind->mlx, wind->win, 5, 103, 0x00FF00,
			"Height - : -");
}

void	ft_move_map(int keycode, t_window *wind)
{
	t_pix *tmp;

	tmp = wind->pix;
	mlx_clear_window(wind->mlx, wind->win);
	if (keycode == 126 || keycode == 125)
		while (tmp)
		{
			if (keycode == 126)
				tmp->y = tmp->y - 20;
			else
				tmp->y = tmp->y + 20;
			tmp = tmp->n;
		}
	if (keycode == 124 || keycode == 123)
		while (tmp)
		{
			if (keycode == 124)
				tmp->x = tmp->x + 20;
			else
				tmp->x = tmp->x - 20;
			tmp = tmp->n;
		}
	ft_zaholovok(wind);
	ft_horizon(wind->pix, wind);
}

void	ft_zoom_map(int keycode, t_window *wind)
{
	t_pix *tmp;

	tmp = wind->pix;
	mlx_clear_window(wind->mlx, wind->win);
	if (keycode == 69)
	{
		wind->krok = wind->krok * 1.1;
		wind->vidy = wind->vidy - (wind->krok * 0.6);
		wind->vidx = wind->vidx - (wind->krok * 0.2);
	}
	else
	{
		wind->krok = wind->krok * 0.9;
		wind->vidy = wind->vidy + (wind->krok * 0.8);
		wind->vidx = wind->vidx + (wind->krok * 0.3);
	}
	ft_perepus(wind);
	ft_zaholovok(wind);
	ft_horizon(tmp, wind);
}

void	ft_height(int keycode, t_window *wind)
{
	t_pix *tmp;

	tmp = wind->pix;
	mlx_clear_window(wind->mlx, wind->win);
	if (keycode == 24)
		while (tmp)
		{
			if (tmp->z != 0)
				tmp->y = tmp->y - 5;
			tmp = tmp->n;
		}
	else
		while (tmp)
		{
			if (tmp->z != 0)
				tmp->y = tmp->y + 5;
			tmp = tmp->n;
		}
	tmp = wind->pix;
	ft_zaholovok(wind);
	ft_horizon(tmp, wind);
}
