/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:15:48 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 12:15:48 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_map_lines(t_data *data, char **file, int i)
{
	int	start;
	int	j;

	start = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->mapinfo.index_end_of_map = i;
	return (i - start);
}

static int	fill_map(t_mapinfo *mapinfo, char **map, int index)
{
	int		i;
	int		j;

	mapinfo->width = largest_width(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (mapinfo->width + 1));
		if (!map[i])
			return (display_error("Memory Allocation Failed", 1));
		while (mapinfo->mapfile[index][j] && mapinfo->mapfile[index][j] != '\n')
		{
			map[i][j] = mapinfo->mapfile[index][j];
			j++;
		}
		while (j < mapinfo->width)
			map[i][j++] = '\0';
		i++;
		index++;
	}
	map[i] = NULL;
	return (SUCCESS);
}

static int	get_game_map(t_data *data, char **file, int i)
{
	data->mapinfo.height = count_map_lines(data, file, i);
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (display_error("Memory Allocation Failed", 1));
	if (fill_map(&data->mapinfo, data->map, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	change_space_into_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
		|| data->map[i][j] == '\r'
		|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
			j++;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' '
				&& j != data->map[i][ft_strlen(data->map[i]) - 1])
				data->map[i][j] = '1';
		}
		i++;
	}
}

int	create_map(t_data *data, char **file, int i)
{
	if (get_game_map(data, file, i) == FAILURE)
		return (FAILURE);
	change_space_into_wall(data);
	return (SUCCESS);
}
