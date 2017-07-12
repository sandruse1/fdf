/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:57:37 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 18:09:23 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*dd(char *dd, char const *s, int n, int j)
{
	int i;

	i = 0;
	dd = (char*)malloc(sizeof(char) * (n + 2));
	if (dd == NULL)
		return (0);
	while (n + 1 > 0)
	{
		dd[i] = s[j];
		n--;
		i++;
		j++;
	}
	dd[i] = '\0';
	return (dd);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*d;

	i = 0;
	n = 0;
	d = NULL;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	while (s[i + 1])
	{
		i++;
		n++;
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		n--;
	}
	d = dd(d, s, n, j);
	return (d);
}
