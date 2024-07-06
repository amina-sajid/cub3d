/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:38:30 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 15:15:25 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	size_t			i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)(s);
	while (i < n)
	{
		if (src[i] == (unsigned char)(c))
			return (src + i);
	i++;
	}
	return (0);
}
