/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:58:14 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/07 12:33:04 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_3strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strnstr(char *big, char *lit, size_t len)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	j = 0;
	n = ft_3strlen(lit);
	if (n == 0)
		return (big);
	while (big[j] && j < len)
	{
		while (lit[i] == big[j + i] && (i + j) < len)
		{
			if (i == n - 1)
				return ((char*)big + j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
