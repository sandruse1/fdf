/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:57:51 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 18:08:51 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*d;

	i = 0;
	d = (void*)malloc(size);
	if (d == NULL)
		return (0);
	while (i < size)
		*((char*)d + i++) = 0;
	return (d);
}
