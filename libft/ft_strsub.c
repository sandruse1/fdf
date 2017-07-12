/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:00:23 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 18:09:53 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*d;

	i = 0;
	if (!s)
		return (0);
	d = (char*)malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (0);
	while (i < len && s[start])
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}
