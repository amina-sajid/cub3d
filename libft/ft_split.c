/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:40:06 by asajid            #+#    #+#             */
/*   Updated: 2023/01/27 12:56:37 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter.
	The array must end with a NULL pointer.
	Returns the array of new strings resulting from the split.
	Returns NULL if the allocation fails.
	s: The string to be split.
	c: The delimiter character.
	1. Get the total number of words and allocate the number + 1 to malloc
	2. Get the total length of each word and allocate to malloc
*/

#include "libft.h"

static int	word_count(const char *str, char c)
{
	size_t	i;
	size_t	toggle;

	i = 0;
	toggle = 0;
	while (*str)
	{
		if (*str != c && toggle == 0)
		{
			toggle = 1;
			i++;
		}
		else if (*str == c)
			toggle = 0;
		str++;
	}
	return (i);
}

static int	word_length(const char *str, char c)
{
	size_t	wordlength;

	if (!ft_strchr (str, c))
		wordlength = ft_strlen (str);
	else
		wordlength = ft_strchr (str, c) - str;
	return (wordlength);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	size_t	i;

	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			split[i++] = ft_substr (str, 0, word_length (str, c));
			str = str + word_length (str, c);
		}
	}
	split[i] = NULL;
	return (split);
}
