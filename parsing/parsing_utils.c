/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:03:59 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 20:03:59 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	largest_width(t_mapinfo *map, int i)
{
	size_t	width;

	width = ft_strlen(map->mapfile[i]);
	while (map->mapfile[i])
	{
		if (ft_strlen(map->mapfile[i]) > width)
			width = ft_strlen(map->mapfile[i]);
		i++;
	}
	return (width);
}

int	is_a_white_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (1);
	else
		return (0);
}
