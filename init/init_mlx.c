/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:56:14 by asajid            #+#    #+#             */
/*   Updated: 2024/04/28 16:56:14 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("mlx error\n", 2);
		ft_exit(data, 1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
	{
		ft_putstr_fd("error in window creation\n", 2);
		ft_exit(data, 1);
	}
	return ;
}
