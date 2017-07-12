/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:45:42 by sandruse          #+#    #+#             */
/*   Updated: 2016/12/06 17:29:44 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*buf;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	buf = f(lst);
	new_lst = ft_lstnew(buf->content, buf->content_size);
	if (new_lst)
	{
		tmp = new_lst;
		lst = lst->next;
		while (lst)
		{
			buf = f(lst);
			tmp->next = ft_lstnew(buf->content, buf->content_size);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
