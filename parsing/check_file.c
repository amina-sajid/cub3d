/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 07:12:04 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 07:12:04 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	checkif_dir(char *arg)
{
	int	fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (1);
	}
	return (0);
}

int	checkif_cubfile(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'
			|| arg[len - 4] != '.'))
		return (1);
	return (0);
}

int	checkif_file_valid(char *arg)
{
	int	fd;

	if (checkif_dir(arg))
		return (display_error("It is a Directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (display_error(strerror(errno), 1));
	close (fd);
	if (checkif_cubfile(arg))
		return (display_error("It not a .cub file", 1));
	return (0);
}

int	check_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (1);
	return (0);
}

int	check_valid_xpm(char *arg)
{
	int	fd;

	if (checkif_dir(arg))
		return (display_error("It is a Directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (display_error(strerror(errno), 1));
	close (fd);
	if (check_xpm_file(arg))
		return (display_error("It not a .xpm file", 1));
	return (0);
}
