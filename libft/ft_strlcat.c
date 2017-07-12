/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:05:54 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/07 12:29:32 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t a;

	i = 0;
	j = 0;
	a = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	a = j;
	if (size < i)
		return ((unsigned long)j + (unsigned long)size);
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (((unsigned long)a - j) + (unsigned long)i);
}
