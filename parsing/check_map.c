/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:52:53 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 20:52:53 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_char(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r'
			|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (display_error("Invalid character", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (display_error("Map has more than one player", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_pos_valid(t_data *data, char **map)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map[i - 1]) <= (size_t)j
		|| ft_strlen(map[i + 1]) <= (size_t)j
		|| is_a_white_space(map[i][j - 1]) == 0
		|| is_a_white_space(map[i][j + 1]) == 0
		|| is_a_white_space(map[i - 1][j]) == 0
		|| is_a_white_space(map[i + 1][j]) == 0)
		return (1);
	return (0);
}

static int	check_player_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (display_error("Player position is missing", 1));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (is_pos_valid(data, map_tab) == 1)
		return (display_error("Invalid Player Position!", 1));
	return (0);
}

static int	check_mapfile_last(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->mapfile[i])
	{
		j = 0;
		while (map->mapfile[i][j])
		{
			if (map->mapfile[i][j] != ' ' && map->mapfile[i][j] != '\t'
				&& map->mapfile[i][j] != '\r' && map->mapfile[i][j] != '\n'
				&& map->mapfile[i][j] != '\v' && map->mapfile[i][j] != '\f')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_validity(t_data *data, char **map_tab)
{
	if (!data->map)
		return (display_error("Map Missing", 1));
	if (data->mapinfo.height < 3)
		return (display_error("Map too small!", 1));
	if (check_map_borders(&data->mapinfo, map_tab) == 1)
		return (display_error("Map is not surrounded by walls!", 1));
	if (check_char(data, map_tab) == 1)
		return (1);
	if (check_player_position(data, map_tab) == 1)
		return (1);
	if (check_mapfile_last(&data->mapinfo) == 1)
		return (display_error("Map is not the Last Element in mapfile", 1));
	return (0);
}
