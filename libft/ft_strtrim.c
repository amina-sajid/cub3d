/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:11:47 by asajid            #+#    #+#             */
/*   Updated: 2023/01/27 15:30:15 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.
	s1: The string to be trimmed.
	set: The reference set of characters to trim.
	Returns the trimmed string and NULL if the allocation fails.
	loop thru the string s1, take its first character
	and search if its in the list of charaters in set
	if found there, keep moving forward till you dont see a match
	once a match is not found, store the int location
	now search again starting from the end of string s1 backwards
	once no match is found store the location
	when you subtract both locations compensating for the null
	you get the number of characters to be allocated to malloc
	now start printing to malloc starting from the start location
	stop at the end location
*/

#include"libft.h"

int	ft_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;
	char	*ptr;

	if (!s1)
		return (0);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check(s1[start], set))
		start++;
	while (end > start && ft_check(s1[end - 1], set))
		end--;
	len = end - start;
	ptr = malloc((sizeof (char)) * (len + 1));
	if (!ptr)
		return (0);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
