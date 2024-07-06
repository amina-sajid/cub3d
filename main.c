/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:43:05 by asajid            #+#    #+#             */
/*   Updated: 2024/04/28 10:43:05 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (checkif_file_valid(av[1]) == 1)
		ft_exit(data, 1);
	parse_data(av[1], data);
	if (check_map_file(data, data->mapinfo.mapfile) == 1)
		return (free_data(data));
	if (check_map_validity(data, data->map) == FAILURE)
		return (free_data(data));
	if (check_texture_fc(data, &data->texinfo) == FAILURE)
		return (free_data(data));
	init_player_direction(data);
	return (0);
}

int	redraw(t_data *data)
{
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	init_texture_pixels(data);
	return (0);
}

void	execute(t_data *data)
{
	init_mlx(data);
	get_textures(data);
	init_texture_pixels(data);
	directions(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("wrong format\n./cub3D <maps>\n", 2), 1);
	init_data(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	execute(&data);
	mlx_loop_hook(data.mlx, redraw, &data);
	mlx_loop(data.mlx);
	return (0);
}
