/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:55:01 by asajid            #+#    #+#             */
/*   Updated: 2024/04/27 14:55:01 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		image->addr[y * (image->size_line / 4) + x]
			= data->texture_pixels[y][x];
	else if (y < data->win_height / 2)
		image->addr[y * (image->size_line / 4) + x] = data->texinfo.hex_ceiling;
	else if (y < data->win_height - 1)
		image->addr[y * (image->size_line / 4) + x]
			= data->texinfo.hex_floor;
}

void	draw(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_image(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		double_free((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
	{
		ft_putstr_fd("allocation failed", 2);
		ft_exit(data, 1);
	}
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
		{
			ft_putstr_fd("allocation failed", 2);
			ft_exit(data, 1);
		}
		i++;
	}
	raycast(&data->player, data);
	draw(data);
}
