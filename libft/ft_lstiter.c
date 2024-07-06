/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:59:29 by asajid            #+#    #+#             */
/*   Updated: 2023/01/27 14:59:32 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
