/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:33:02 by mcombeau          #+#    #+#             */
/*   Updated: 2024/04/28 16:56:50 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_exit(t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	free_data(data);
	exit(code);
}

int	quit_cub3d(t_data *data)
{
	ft_exit(data, 0);
	return (0);
}
