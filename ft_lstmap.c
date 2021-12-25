/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:54:50 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/07 08:35:51 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	new_list = NULL;
	while (lst != NULL)
	{
		current = ft_lstnew((*f)(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&current, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, current);
		lst = lst->next;
	}
	return (new_list);
}
