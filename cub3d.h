/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajid <asajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:46:36 by asajid            #+#    #+#             */
/*   Updated: 2024/04/28 10:46:36 by asajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# ifndef MMAP_DEBUG_MSG
#  define MMAP_DEBUG_MSG 0
# endif

# ifndef BONUS
#  define BONUS 1
# endif

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

# define MOVESPEED 0.0125
# define ROTSPEED 0.015

# define DIST_EDGE_MOUSE_WRAP 20

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_ESC	53

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**mapfile;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;

}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_data;

void	init_data(t_data *data);
void	init_image_struct(t_img *img);
void	init_ray(t_ray *ray);
void	init_mlx(t_data *data);
void	init_image(t_data *data, t_img *image, int width, int height);
void	init_texture_img(t_data *data, t_img *image, char *path);
void	get_textures(t_data *data);
void	init_texinfo(t_texinfo *textures);
void	parse_data(char *file, t_data *data);
int		checkif_file_valid(char *arg);
int		check_map_file(t_data *data, char **map);
int		check_map_validity(t_data *data, char **map_tab);
int		check_texture_fc(t_data *data, t_texinfo *textures);
int		check_xpm_file(char *arg);
int		check_valid_xpm(char *arg);
int		fill_color(t_data *data, t_texinfo *textures, char *line, int j);
int		create_map(t_data *data, char **file, int i);
int		display_error(char *msg, int err_code);
int		check_map_borders(t_mapinfo *t_map, char **map);
int		is_a_white_space(char c);
size_t	largest_width(t_mapinfo *map, int i);
int		render(t_data *data);
void	render_images(t_data *data);
void	execute(t_data *data);
int		raycast(t_player *player, t_data *data);
void	init_texture_pixels(t_data *data);
void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x);
void	directions(t_data *data);
void	init_player_direction(t_data *data);
int		validate_move(t_data *data, double new_x, double new_y);
int		move_player(t_data *data);
int		rotate_player(t_data *data, double rotdir);
void	ft_exit(t_data *data, int code);
int		quit_cub3d(t_data *data);
void	double_free(void **tab);
int		free_data(t_data *data);
void	debug_display_player(t_data *data);
void	debug_print_char_tab(char **tab);
void	draw(t_data *data);
#endif
