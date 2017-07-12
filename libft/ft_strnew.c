/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:39:59 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/07 11:12:15 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*d;
	size_t	i;

	i = 0;
	d = (char*)malloc(sizeof(char) * size + 1);
	if (d == NULL)
		return (0);
	while (i < size + 1)
		d[i++] = '\0';
	return (d);
}
