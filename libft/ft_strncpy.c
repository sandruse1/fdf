/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:01:27 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 13:25:14 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (len != 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len != 0)
	{
		dst[i++] = '\0';
		len--;
	}
	return (dst);
}
