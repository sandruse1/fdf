/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:39 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 11:21:50 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (dst >= src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char*)dst + i) = *((char*)src + i);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((char*)dst + i) = *((char*)src + i);
			i++;
		}
	}
	return (dst);
}
