/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:42:09 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 14:44:48 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlcpy() copies up to dstsize -1 characters from the string src to dst,
nul terminating  the result if dstsize is not 0
If the src and dst strings overlap, the behaviour is undefined.
Returns the length  of src
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}
