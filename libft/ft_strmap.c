/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:24:38 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 18:07:07 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*d;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	d = (char*)malloc(sizeof(char) * i + 1);
	if (d == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		d[i] = f(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
