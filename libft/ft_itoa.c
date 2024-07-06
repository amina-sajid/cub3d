/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:46:42 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 14:07:53 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.
	Returns the string representing the integer.
	Returns NULL if the allocation fails
	convert integer to string

*/
#include "libft.h"

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ret;
	const char	*digits = "0123456789";

	len = ft_numlen(n, 10);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
}
