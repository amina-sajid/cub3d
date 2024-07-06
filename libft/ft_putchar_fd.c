/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:59:10 by asajid            #+#    #+#             */
/*   Updated: 2023/01/26 14:12:37 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the character ’c’ to the given file descriptor.
	c: The character to output.
	fd: The file descriptor on which to write.

*/

#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
