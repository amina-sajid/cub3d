/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:51:06 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 15:16:32 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3))and returns  a new node.j
The member variable 'content'
is initialized with the value of the parameter content,
The variable 'next' is initialized to NULL.
*/

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
