/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:20:28 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/21 00:20:28 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_first_last(char **map, int i, int j)
{
	if (!map || !map[i] || !map[i][j])
		return (1);
	while (map[i][j] == ' ' || map[i][j] == '\t'
	|| map[i][j] == '\r' || map[i][j] == '\v'
	|| map[i][j] == '\f')
		j++;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_map_borders(t_mapinfo *t_map, char **map)
{
	int	i;
	int	j;

	if (check_first_last(map, 0, 0) == 1)
		return (1);
	i = 1;
	while (i < (t_map->height - 1))
	{
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			return (1);
		i++;
	}
	if (check_first_last(map, i, 0) == 1)
		return (1);
	return (0);
}
