/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:52:49 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/07 16:35:35 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_what(long long t)
{
	if (t < 0)
		return (1);
	return (0);
}

static char			*ft_strrev1(char *str, int j)
{
	int				i;
	char			c;

	i = 0;
	while (j > i)
	{
		c = str[i];
		str[i++] = str[j];
		str[j--] = c;
	}
	return (str);
}

static long long	mall(long long n)
{
	long long c;
	long long l;

	c = 1;
	l = 1;
	while (c * 10 < n)
	{
		c *= 10;
		l++;
	}
	return (l);
}

char				*ft_itoa(int n)
{
	char			*s;
	long long		i;
	long long		m;
	int				k;
	long long		t;

	t = n;
	i = 0;
	k = ft_what(t);
	if (k == 1)
		t = -t;
	m = mall(t);
	s = (char*)malloc(sizeof(char) * (m + k + 1));
	if (s == NULL)
		return (0);
	while (i < m)
	{
		s[i++] = t % 10 + '0';
		t /= 10;
	}
	if (k == 1)
		s[i++] = '-';
	s[i] = '\0';
	ft_strrev1(s, i - 1);
	return (s);
}
