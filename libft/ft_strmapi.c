/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:58:05 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 16:12:17 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function ’f’ to each character of the
	string ’s’, and passing its index as first argument
	to create a new string (with malloc(3)) resulting
	from successive applications of ’f’.
	s: The string on which to iterate.
	f: The function to apply to each character.
	Returns the string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (0);
	ptr = (char *) malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
