/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:31:03 by mcombeau          #+#    #+#             */
/*   Updated: 2024/04/28 16:53:16 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	key_press_handler(int key, t_data *data)
{
	if (key == KEY_ESC)
		quit_cub3d(data);
	if (key == KEY_W)
		data->player.move_y = 1;
	if (key == KEY_S)
		data->player.move_y = -1;
	if (key == KEY_D)
		data->player.move_x = 1;
	if (key == KEY_A)
		data->player.move_x = -1;
	if (key == KEY_RIGHT)
		data->player.rotate = 1;
	if (key == KEY_LEFT)
		data->player.rotate = -1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == KEY_ESC)
		quit_cub3d(data);
	if (key == KEY_W && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == KEY_S && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == KEY_D && data->player.move_x == 1)
		data->player.move_x = 0;
	if (key == KEY_A && data->player.move_x == -1)
		data->player.move_x = 0;
	if (key == KEY_RIGHT && data->player.rotate >= -1)
		data->player.rotate = 0;
	if (key == KEY_LEFT && data->player.rotate <= 1)
		data->player.rotate = 0;
	return (0);
}

void	directions(t_data *data)
{
	mlx_hook(data->win, 17, 0, quit_cub3d, data);
	mlx_hook(data->win, 2, 0, key_press_handler, data);
	mlx_hook(data->win, 3, 0, key_release_handler, data);
}
