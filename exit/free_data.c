/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:33:30 by mcombeau          #+#    #+#             */
/*   Updated: 2024/04/23 15:04:41 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	double_free(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_texinfo(t_texinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

static void	free_map(t_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.mapfile)
		double_free((void **)data->mapinfo.mapfile);
	if (data->map)
		double_free((void **)data->map);
}

int	free_data(t_data *data)
{
	if (data->textures)
		double_free((void **)data->textures);
	if (data->texture_pixels)
		double_free((void **)data->texture_pixels);
	free_texinfo(&data->texinfo);
	free_map(data);
	return (FAILURE);
}
