/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:44:01 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 14:01:12 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)s ;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
	s = src;
}
