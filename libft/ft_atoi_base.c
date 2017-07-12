/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:05:44 by sandruse          #+#    #+#             */
/*   Updated: 2017/02/18 12:19:26 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_help1(char **str, int i)
{
	ft_capital((*str));
	while ((*str)[i] < 33)
		i++;
	return (i);
}

int		ft_atoi_base(char *s2, int str_base)
{
	int		i;
	char	j;
	int		k;
	int		b;

	i = ft_help1(&s2, 0);
	k = 0;
	if (s2[i] == 43 || s2[i] == 45)
		j = s2[i++];
	if (str_base <= 10)
		while (s2[i] >= 48 && s2[i] < (48 + str_base))
			k = k * str_base + s2[i++] - '0';
	else
		while ((s2[i] >= 48 && s2[i] < 58)
			|| (s2[i] >= 65 && s2[i] <= (65 + (str_base - 10))))
		{
			if (s2[i] >= 48 && s2[i] < 58)
				b = s2[i++] - '0';
			else
				b = s2[i++] - 55;
			k = k * str_base + b;
		}
	if (j == '-' && str_base == 10)
		return (-k);
	return (k);
}
