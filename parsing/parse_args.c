/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 07:05:49 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/04/20 07:05:49 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_lines(char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		display_error(strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (count);
}

static void	create_mapfile(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->mapinfo.fd);
	while (line != NULL)
	{
		data->mapinfo.mapfile[row] = ft_calloc(ft_strlen(line) + 1,
				sizeof(char));
		if (!data->mapinfo.mapfile[row])
		{
			display_error("Memory Allocation Failed", 1);
			return (double_free((void **)data->mapinfo.mapfile));
		}
		while (line[i] != '\0')
			data->mapinfo.mapfile[row][column++] = line[i++];
		data->mapinfo.mapfile[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->mapinfo.fd);
	}
	data->mapinfo.mapfile[row] = NULL;
}

void	parse_data(char *file, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->mapinfo.path = file;
	data->mapinfo.line_count = count_lines(file);
	data->mapinfo.mapfile = ft_calloc(data->mapinfo.line_count \
			+ 1, sizeof(char *));
	if (!(data->mapinfo.mapfile))
	{
		display_error("Memory Allocation Failed", 1);
		return ;
	}
	data->mapinfo.fd = open(file, O_RDONLY);
	if (data->mapinfo.fd < 0)
		display_error(strerror(errno), errno);
	else
	{
		create_mapfile(row, column, i, data);
		close(data->mapinfo.fd);
	}
}
