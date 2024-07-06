/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:22:48 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 15:05:53 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A file identifier is a number that identifies and opens a
file in the computers operating system */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write (fd, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = 48 + (num % 10);
	write (fd, &c, 1);
}
