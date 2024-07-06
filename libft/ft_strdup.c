/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:48:19 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 16:08:43 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const	char*s1)
{
	char	*dup;
	size_t	n;

	n = 0;
	dup = malloc(sizeof (char) * ft_strlen(s1) + 1);
	if (!dup)
		return (0);
	while (s1[n])
	{
		dup[n] = s1[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
