/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:57:28 by sandruse          #+#    #+#             */
/*   Updated: 2017/02/18 14:43:49 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_valid_file(char *s)
{
	int i;

	i = 0;
	ft_capital(s);
	while (s[i])
		if (s[i] == ' ' || (s[i] >= '0' && s[i] <= '9') || s[i] == 'X'
				|| (s[i] >= 'A' && s[i] <= 'F') || s[i] == ',')
			i++;
		else
			fdf_error(5);
}

void	fdf_error(int n)
{
	if (n == 1)
		ft_putendl("\x1b[31m\tusage: ./fdf [file name]");
	if (n == 2)
		ft_putendl("\x1b[31m\tOpen error");
	if (n == 3)
		ft_putendl("\x1b[31m\tClose() error");
	if (n == 4)
		ft_putendl("\x1b[31m\tColor in file is not valid");
	if (n == 5)
		ft_putendl("\x1b[31m\tFile not valid");
	exit(0);
}

void	ft_valid_color(char *s)
{
	int i;

	i = 0;
	ft_capital(s);
	if (ft_strlen(s) > 8)
		fdf_error(4);
	if (s[0] == '0' && s[1] == 'X')
		i = i + 2;
	else
		fdf_error(4);
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F'))
			i++;
		else
			fdf_error(4);
	}
}

void	ft_valid_len(int i, t_len **len)
{
	if ((*len)->len == 0)
		(*len)->len = i;
	else if ((*len)->len != i)
		fdf_error(5);
}
