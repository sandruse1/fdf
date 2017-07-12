/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:23:41 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/09 16:39:17 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct		s_pix
{
	int				x;
	int				y;
	int				x0;
	int				y0;
	int				z;
	int				c;
	struct s_pix	*n;
}					t_pix;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	char			*name;
	int				width;
	int				height;
	int				krok;
	int				vidx;
	int				vidy;
	t_pix			*pix;
}					t_window;

typedef struct		s_len
{
	int				len;
}					t_len;

typedef struct		s_line
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
	int				x1;
	int				y1;
	int				y2;
	int				color;
	int				x2;
}					t_line;

void				fdf_error(int n);
void				ft_valid_color(char *s);
void				ft_valid_len(int i, t_len **len);
void				ft_valid_file(char *s);
t_pix				*fdf_create_struct(int fd);
void				ft_window(t_pix *p, char *name);
void				ft_line(t_pix *a, t_pix *b, t_window *wind);
void				ft_window_size(t_window **wind, t_pix **p);
void				ft_zaholovok(t_window *wind);
void				ft_horizon(t_pix *p, t_window *wind);
void				ft_move_map(int keycode, t_window *wind);
void				ft_zoom_map(int keycode, t_window *wind);
void				ft_perepus(t_window *win);
void				ft_height(int keycode, t_window *wind);

#endif
