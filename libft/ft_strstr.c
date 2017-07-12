/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:43:23 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 17:54:54 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_1strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_1strlen(little);
	if (n == 0)
		return ((char*)big);
	while (big[j])
	{
		while (little[i] == big[j + i])
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
