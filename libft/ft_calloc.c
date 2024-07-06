/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:22:39 by asajid            #+#    #+#             */
/*   Updated: 2023/01/27 15:32:42 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	n;

	i = 0;
	n = size * count;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = (malloc(n));
	if (!ptr)
		return (0);
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
