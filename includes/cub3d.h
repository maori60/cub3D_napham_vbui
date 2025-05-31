/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/31 00:29:19 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* Window and texture config */
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define TEX_SIZE 64

/* Error messages */
# define ERR_USAGE "Usage: ./cub3d <path/to/map.cub>"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MLX_IMG_LOAD_FAIL "Could not load texture image"
# define ERR_MAP_FILE_OPEN "Could not open map file"
# define ERR_MAP_MEMORY "Memory allocation error"
# define ERR_MAP_FORMAT "Invalid map format"
# define ERR_MAP_NOT_CLOSED "Map is not closed properly"
# define ERR_MAP_MULTIPLE_PLAYERS "Multiple player positions found"
# define ERR_MAP_MISSING_ELEMENTS "Missing required map elements"
# define ERR_MAP_INVALID_CHAR "Invalid character in map"
# define ERR_MAP_SMALL "Map is too small"

# define SUCCESS 0
# define FAILURE 1

// From minilibx
typedef struct s_img
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bits_per_pixel;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}					t_img;

typedef struct s_textures
{
	t_img			*north;
	t_img			*south;
	t_img			*west;
	t_img			*east;
}					t_textures;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	int				floor_color;
	int				ceiling_color;
	int				player_x;
	int				player_y;
	char			player_orientation;
	int				element_count;
}					t_map;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			tex_pos;
	double			tex_step;
}					t_ray;

typedef struct s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
	int				esc;
}					t_keys;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_map			*map;
	t_player		player;
	t_textures		textures;
	t_keys			keys;
}					t_game;

t_map				*load_map(char *path);
void				free_map(t_map *m);
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					render_frame(t_game *game);
void				err_msg(char *context, char *message);
void				*ft_memset(void *b, int c, size_t len);
int					exit_game(t_game *game);
#endif
