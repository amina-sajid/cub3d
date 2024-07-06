/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:50:40 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 15:15:58 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Counts the number of nodes in a list.
	lst: The beginning of the list.
	Returns The length of the list

	• content: The data contained in the node.
	void * allows to store any kind of data.
	• next: The address of the next node, or NULL if the next node is the last one.
*/

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
