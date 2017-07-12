/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:48:06 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/07 13:40:57 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	s2 = (char*)malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i])
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}
