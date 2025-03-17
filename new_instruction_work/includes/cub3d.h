/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/03/17 17:01:26 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stddef.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h" // Inclusion de MiniLibX

// Définition des dimensions de la fenêtre
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEX_SIZE 64

// Macros d'erreur manquantes (ajoutées)
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

// Définition de succès et échec
# define SUCCESS 0
# define FAILURE 1

// Enum pour les indices des textures
typedef enum e_texture_index {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
} t_texture_index;

// Structure pour une image MLX
typedef struct s_img {
    void    *img;
    int     *addr;
    int     pixel_bits;
    int     size_line;
    int     endian;
} t_img;

// Structure pour les textures et couleurs
typedef struct s_texinfo {
    char            *north;
    char            *south;
    char            *west;
    char            *east;
    t_img           textures[4];
    int             *floor;
    int             *ceiling;
    unsigned int   hex_floor;
    unsigned int   hex_ceiling;
    int             floor_color;
    int             ceiling_color;
    int             width;   // Ajout pour la largeur des textures
    int             height;  // Ajout pour la hauteur des textures
} t_texinfo;


// Structure pour la position du joueur
typedef struct s_player {
    double  pos_x;
    double  pos_y;
    char    dir;
} t_player;

// Structure pour la carte
typedef struct s_mapinfo {
    char    **file;
    char    **map;
    int     width;
    int     height;
} t_mapinfo;

// Structure principale pour les données du programme
typedef struct s_data {
    void        *mlx;
    void        *win;
    t_mapinfo   mapinfo;
    t_texinfo   texinfo;
    t_player    player;
    void        **textures;
} t_data;

// Fonctionnalités liées à la validation des arguments (args_checker.c)
int validate_file_path(char *filename, int is_map_file);

// Fonctionnalités liées au chargement des fichiers (file_loader.c)
int load_map_file(char *filepath, t_data *data);

// Fonctionnalités liées à la validation des textures et couleurs (texture_checker.c)
int validate_textures_and_colors(t_data *data, t_texinfo *textures);

// Fonctionnalités liées à la validation de la carte (map_validator.c)
int validate_map_walls(char **map, int height);

// Fonctionnalités liées aux bordures de la carte (map_boundaries.c)
int validate_map_boundaries(char **map, int height);

// Fonctionnalités liées au chargement de la carte (map_loader.c)
int load_map_data(char **lines, t_data *data, int start);

// Fonctionnalités liées à la position du joueur (player_position.c)
int validate_player_position(t_data *data);

// Fonctionnalités liées au parsing des couleurs RGB (rgb_parser.c)
int parse_rgb_colors(t_texinfo *textures, char *line, int is_floor);
// unsigned long rgb_to_hex(int *rgb);
unsigned int rgb_to_hex(int r, int g, int b);


// Outils génériques (ajout de `display_error_message` pour éviter implicit declaration)
int display_error_message(char *context, char *message, int return_code);
void free_data(t_data *data);
void clean_exit(t_data *data, int exit_code);
int err_msg(char *prefix, char *message, int exit_code);

// Parsing/file_loader.c
int count_file_lines(char *filepath);
int load_file_content(char **content, int fd);
int parse_texture_line(char *line, t_data *data);
int validate_map_borders(char **map, int height);
int validate_map_characters(char **map, int height, int width);
int validate_map_spaces(char **map, int height, int width);
int validate_floor_and_ceiling(t_texinfo *texinfo);

// Déclaration des fonctions liées à MLX
void init_mlx(t_data *data);
void init_img(t_data *data, t_img *image, int width, int height);
void init_texture_img(t_data *data, t_img *image, char *path);

// Déclaration de la fonction pour initialiser les textures
void init_textures(t_data *data);

// Déclaration de la fonction pour initialiser texinfo
void init_texinfo(t_texinfo *textures);

// Ajout de la déclaration de find_map_start pour éviter l'erreur d'implicit declaration
int find_map_start(char **file);


#endif
