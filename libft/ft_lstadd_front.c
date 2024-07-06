/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:18:55 by asajid            #+#    #+#             */
/*   Updated: 2024/04/30 10:24:07 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Adds the node ’new’ at the beginning of the list.
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be dded to the list
	1. store the address in list to the new-> next
	2. store the new elements address in list
*/
#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
