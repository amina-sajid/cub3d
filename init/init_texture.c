/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:47:44 by asajid            #+#    #+#             */
/*   Updated: 2024/04/28 16:47:44 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_image_addrs(int *buffer, t_img tmp, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			buffer[y * size + x] = tmp.addr[y * size + x];
			++x;
		}
		y++;
	}
}

void	init_image_struct(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

static int	*get_image(t_data *data, char *path, int size)
{
	t_img	tmp;
	int		*buffer;

	init_image_struct(&tmp);
	tmp.img = mlx_xpm_file_to_image(data->mlx, path, &size, &size);
	if (tmp.img == NULL)
	{
		ft_putstr_fd("error\n", 2);
		ft_exit(data, 1);
	}
	tmp.addr = (int *)mlx_get_data_addr(tmp.img, &tmp.pixel_bits, \
		&tmp.size_line, &tmp.endian);
	buffer = ft_calloc(1, sizeof(*buffer) * size * size);
	if (!buffer)
	{
		ft_putstr_fd("allocation error\n", 2);
		ft_exit(data, 1);
	}
	get_image_addrs(buffer, tmp, size);
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	get_textures(t_data *data)
{
	int	size;

	size = data->texinfo.size;
	data->textures = ft_calloc(5, sizeof(*data->textures));
	if (!data->textures)
	{
		ft_putstr_fd("allocation error", 2);
		ft_exit(data, 1);
	}
	data->textures[NORTH] = get_image(data, data->texinfo.north, size);
	data->textures[SOUTH] = get_image(data, data->texinfo.south, size);
	data->textures[EAST] = get_image(data, data->texinfo.east, size);
	data->textures[WEST] = get_image(data, data->texinfo.west, size);
}

void	init_texinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->ceiling = 0;
	textures->floor = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
