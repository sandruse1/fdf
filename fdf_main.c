/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:58:40 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/11 12:15:18 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_pix	*pixel;

	if (argc != 2)
		fdf_error(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fdf_error(2);
	pixel = fdf_create_struct(fd);
	ft_window(pixel, argv[1]);
	return (0);
}
