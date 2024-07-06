/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 07:22:54 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 07:22:54 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display_error(char *msg, int err_code)
{
	ft_putstr_fd("cub3D: Error", 2);
	if (msg)
	{
		ft_putstr_fd(":", 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(msg, 2);
	}
	return (err_code);
}
