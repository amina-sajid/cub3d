/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:12:13 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/21 09:12:13 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	no_digit(char *str)
{
	int		i;
	bool	found_no_digit;

	i = 0;
	found_no_digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			found_no_digit = false;
		i++;
	}
	return (found_no_digit);
}

static int	*copy_into_rgb_array(char **rgb_char_array, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_char_array[++i])
	{
		rgb[i] = ft_atoi(rgb_char_array[i]);
		if (rgb[i] == -1 || no_digit(rgb_char_array[i]) == true)
		{
			double_free((void **)rgb_char_array);
			free(rgb);
			return (0);
		}
	}
	double_free((void **)rgb_char_array);
	return (rgb);
}

static int	*set_rgb_colors(char *line)
{
	char	**rgb_char_array;
	int		*rgb;
	int		count;

	rgb_char_array = ft_split(line, ',');
	count = 0;
	while (rgb_char_array[count])
		count++;
	if (count != 3)
	{
		double_free((void **)rgb_char_array);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		display_error("Memory Allocation Failed", 1);
		return (0);
	}
	return (copy_into_rgb_array(rgb_char_array, rgb));
}

int	fill_color(t_data *data, t_texinfo *textures, char *line, int j)
{
	(void)data;
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (display_error("Invalid Floor/Ceiling RGB Color", 2));
	if (!textures->ceiling && line[j] == 'C')
	{
		textures->ceiling = set_rgb_colors(line + j + 1);
		if (textures->ceiling == 0)
			return (display_error("Invalid Ceiling RGB Color", 2));
	}
	else if (!textures->floor && line[j] == 'F')
	{
		textures->floor = set_rgb_colors(line + j + 1);
		if (textures->floor == 0)
			return (display_error("Invalid Floor RGB Color", 2));
	}
	else
		return (display_error("Invalid Floor/Ceiling RGB Color", 2));
	return (0);
}
