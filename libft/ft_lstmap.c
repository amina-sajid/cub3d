/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:54:04 by asajid            #+#    #+#             */
/*   Updated: 2023/01/27 15:02:13 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*update;

	if (!lst || !f || !del)
		return (0);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (0);
	update = ptr;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!ptr->next)
		{
			ft_lstclear(&update, del);
			return (0);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (update);
}
