/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:43:02 by asajid            #+#    #+#             */
/*   Updated: 2024/04/30 09:52:18 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.plane_x * MOVESPEED;
	new_y = data->player.pos_y + data->player.plane_y * MOVESPEED;
	if (data->map[(int)new_y][(int)new_x] != '1' )
		return (validate_move(data, new_x, new_y));
	return (0);
}

static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.plane_x * MOVESPEED;
	new_y = data->player.pos_y - data->player.plane_y * MOVESPEED;
	if (data->map[(int)new_y][(int)new_x] != '1')
		return (validate_move(data, new_x, new_y));
	return (0);
}

static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
	if (data->map[(int)new_y][(int)new_x] != '1' )
		return (validate_move(data, new_x, new_y));
	return (0);
}

static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	if ((data->map[(int)new_y][(int)new_x] != '1'))
		return (validate_move(data, new_x, new_y));
	return (0);
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_player_forward(data);
	if (data->player.move_y == -1)
		moved += move_player_backward(data);
	if (data->player.move_x == -1)
		moved += move_player_left(data);
	if (data->player.move_x == 1)
		moved += move_player_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}
