/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:17:48 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 16:04:02 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The terminating null character is also considered a part of the string
//1 is added to the stringlength so that the null character is also checked
#include"libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		len;
	char	*sr;

	len = ft_strlen(s) + 1;
	sr = (char *)(s);
	while (len--)
	{
		if ((sr[len]) == (char)(c))
			return (sr + len);
	}
	return (0);
}
