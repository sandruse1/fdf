/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:11:53 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/16 11:33:51 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_perepus(t_window *win)
{
	int		a;
	int		b;
	t_pix	*tmp;
	int		n;
	int		k;

	n = 0;
	k = 0;
	tmp = win->pix;
	while (tmp)
	{
		a = tmp->x0 + n;
		b = tmp->y0 + k;
		n = n + win->krok;
		if (tmp && tmp->n && (tmp->n->x < tmp->x))
		{
			k = k + win->krok;
			n = 0;
		}
		tmp->x = (a - b) + win->vidx;
		tmp->y = ((a + b) / 2) - tmp->z + win->krok + win->vidy;
		tmp = tmp->n;
	}
}

void	ft_vertical(t_pix *p, t_window *wind)
{
	t_pix *begin;

	begin = p;
	p = p->n;
	while (p->n)
	{
		while ((begin->x < p->x) && p->n)
			p = p->n;
		while (p->n && (p->n->x < begin->x) && (p->n->x > p->x))
			p = p->n;
		ft_line(begin, p, wind);
		if (p->n)
		{
			begin = begin->n;
			p = begin->n;
		}
	}
}

void	ft_horizon(t_pix *p, t_window *wind)
{
	t_pix *tmp;

	tmp = p;
	while (p->n)
	{
		if (p->x > p->n->x)
			p = p->n;
		ft_line(p, p->n, wind);
		p = p->n;
	}
	p = tmp;
	ft_vertical(p, wind);
}

int		my_key_funct(int keycode, t_window *wind)
{
	if (keycode == 53)
		exit(0);
	if (keycode >= 123 && keycode <= 126)
		ft_move_map(keycode, wind);
	if (keycode == 69 || keycode == 78)
		ft_zoom_map(keycode, wind);
	if (keycode == 24 || keycode == 27)
		ft_height(keycode, wind);
	return (0);
}

void	ft_window(t_pix *p, char *name)
{
	t_window	*wind;

	wind = (t_window*)malloc(sizeof(t_window));
	wind->name = name;
	wind->pix = p;
	ft_window_size(&wind, &p);
	wind->mlx = mlx_init();
	wind->win = mlx_new_window(wind->mlx, 1900, 1200, "mlx 42");
	ft_zaholovok(wind);
	ft_perepus(wind);
	ft_horizon(p, wind);
	mlx_key_hook(wind->win, my_key_funct, wind);
	mlx_loop(wind->mlx);
}
