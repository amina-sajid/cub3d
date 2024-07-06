/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:43:27 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 08:43:27 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	fill_direction_textures(t_texinfo *textures, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (2);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
		textures->north = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
		textures->south = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
		textures->west = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
		textures->east = get_texture_path(line, j + 2);
	else
		return (2);
	return (0);
}

int	check_nsew(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	check_each_row(t_data *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && check_nsew(map[i][j])
			&& !ft_isdigit(map[i][j]))
		{
			if (fill_direction_textures(&data->texinfo, map[i], j) == 2)
				return (display_error("Invalid Texture(s)", 1));
			return (3);
		}
		else
		{
			if (fill_color(data, &data->texinfo, map[i], j) == 2)
				return (1);
			return (3);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(data, map, i) == 1)
			return (display_error("Map is either Incomplete/Wrong", 1));
		return (0);
	}
	return (4);
}

int	check_map_file(t_data *data, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = check_each_row(data, map, i, j);
			if (ret == 3)
				break ;
			else if (ret == 1)
				return (1);
			else if (ret == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}
