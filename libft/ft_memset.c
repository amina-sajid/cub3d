/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:37:19 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 15:08:52 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*src ;

	i = 0;
	src = (unsigned char *)b;
	while (i < len)
	{
		src[i] = c;
		i++;
	}
	return (b = src);
}
