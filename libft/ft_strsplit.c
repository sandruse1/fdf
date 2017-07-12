/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:39:05 by sandruse          #+#    #+#             */
/*   Updated: 2017/02/08 12:06:30 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	len(char const *s, char c, int i)
{
	int n;

	n = 0;
	while (s[i] != c && s[i])
	{
		i++;
		n++;
	}
	return (n);
}

static char	**zapow(char **d, char const *s, char c)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		d[j] = (char*)malloc(sizeof(char) * len(s, c, i) + 1);
		if (!d[j])
			return (NULL);
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				d[j][n++] = s[i++];
			d[j++][n] = '\0';
		}
		n = 0;
	}
	d[j] = NULL;
	return (d);
}

char		**ft_strsplit(char const *s, char c)
{
	char **d;

	if (!s || !c)
		return (0);
	d = (char**)malloc(sizeof(char*) * count(s, c) + 1);
	if (!d)
		return (NULL);
	d = zapow(d, s, c);
	return (d);
}
