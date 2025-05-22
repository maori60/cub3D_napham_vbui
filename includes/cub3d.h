/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 21:10:46 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
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
# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

# define SUCCESS 0
# define FAILURE 1

typedef enum e_texture_index
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}					t_texture_index;

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

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	t_img			textures[4];
	int				*floor;
	int				*ceiling;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
	int				floor_color;
	int				ceiling_color;
	int				width;
	int				height;
}					t_texinfo;

typedef struct s_textures
{
	t_img			*north;
	t_img			*south;
	t_img			*west;
	t_img			*east;
	int				floor_color;
	int				ceiling_color;
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

typedef struct s_mapinfo
{
	char			**file;
	char			**map;
	int				width;
	int				height;
}					t_mapinfo;

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
	t_mapinfo		mapinfo;
	t_player		player;
	t_textures		textures;
	t_keys			keys;
}					t_game;

/* Argument validation */
int					validate_file_path(char *filename, int is_map_file);

/* File loading */
int					load_map_file(char *filepath, t_game *data);
int					count_file_lines(char *filepath);
int					load_file_content(char **content, int fd);

/* Texture & color */
int					validate_textures_and_colors(t_game *data,
						t_texinfo *textures);
int					parse_texture_line(char *line, t_game *data);
int					parse_rgb_colors(t_texinfo *textures, char *line,
						int is_floor);
int					validate_floor_and_ceiling(t_texinfo *texinfo);

/* Map validation */
int					validate_map_borders(char **map, int height);
int					validate_map_walls(char **map, int height);
int					validate_map_characters(char **map, int height, int width);
int					validate_map_spaces(char **map, int height, int width);
int					check_wall(char **map, int i, int j, int height);
int					is_space_adjacent(char **map, int i, int j);
void				print_debug_map(char **map, int height);

/* Player */
int					validate_player_position(t_game *data);
int					find_player_position(char **map, t_player *player,
						int height);
/* Map parsing */
int					load_map_data(char **lines, t_game *data, int start);
int					find_map_start(char **file);

/* MLX init */
void				init_mlx(t_game *data);
void				init_texture_img(t_game *data, t_img *image, char *path);
void				init_textures(t_game *data);
void				init_texinfo(t_texinfo *textures);

/* Utilities */
unsigned int		rgb_to_hex(int r, int g, int b);
int					display_error_message(char *ctx, char *msg, int code);
int					err_msg(char *prefix, char *message, int exit_code);
void				clean_exit(t_game *data, int exit_code);
void				free_data(t_game *data);

/* RGB Utilities */
int					*parse_rgb_values(char *line);
void				free_split(char **split);
char				*trim_texture_path(char *line);
int					store_texture(char **texture, char *path);

int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);
int					render_frame(t_game *game);
#endif
