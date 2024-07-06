/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 08:39:42 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/21 08:39:42 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (display_error("Invalid RGB Value(0-255)", 1));
		i++;
	}
	return (0);
}

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	check_texture_fc(t_data *data, t_texinfo *textures)
{
	(void)data;
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (display_error("Texture(s) Missing", 1));
	if (!textures->floor || !textures->ceiling)
		return (display_error("Floor/Ceiling Color Missing", 1));
	if (check_valid_xpm(textures->north) == 1
		|| check_valid_xpm(textures->south) == 1
		|| check_valid_xpm(textures->west) == 1
		|| check_valid_xpm(textures->east) == 1
		|| check_valid_rgb(textures->floor) == 1
		|| check_valid_rgb(textures->ceiling) == 1)
		return (1);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
	return (0);
}
