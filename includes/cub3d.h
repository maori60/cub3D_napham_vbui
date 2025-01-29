/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:08:18 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:19:17 by vbui             ###   ########.fr       */
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

// Macros d'erreur
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

// Structure pour les textures et couleurs
typedef struct s_texinfo {
    char            *north;
    char            *south;
    char            *west;
    char            *east;
    int             *floor;     // Tableau RGB pour le sol
    int             *ceiling;   // Tableau RGB pour le plafond
    unsigned long   hex_floor;
    unsigned long   hex_ceiling;
    int             floor_color;     // Ajoute ceci si manquant
    int             ceiling_color;  
} t_texinfo;

// Structure pour la position du joueur
typedef struct s_player {
    double  pos_x;  // Position X
    double  pos_y;  // Position Y
    char    dir;    // Direction initiale ('N', 'S', 'E', 'W')
} t_player;

// Structure pour la carte
typedef struct s_mapinfo {
    char    **file;    // Toutes les lignes du fichier .cub
    char    **map;     // Tableau représentant la carte
    int     width;     // Largeur maximale de la carte
    int     height;    // Hauteur de la carte
} t_mapinfo;

// Structure principale pour les données du programme
typedef struct s_data {
    t_mapinfo   mapinfo;
    t_texinfo   texinfo;
    t_player    player;
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
unsigned long rgb_to_hex(int *rgb); // Ajout de la fonction

// Outils génériques
int display_error_message(char *context, char *message, int return_code);
void free_data(t_data *data);

// Parsing/file_loader.c
int count_file_lines(char *filepath);
int load_file_content(char **content, int fd);
int parse_texture_line(char *line, t_data *data);
int validate_map_borders(char **map, int height);
int validate_map_characters(char **map, int height, int width);
int validate_map_spaces(char **map, int height, int width);
int validate_floor_and_ceiling(t_texinfo *texinfo);


// Ajout de la déclaration pour éviter les erreurs de compilation
int find_map_start(char **file);

void print_debug_map(char **map, int height);

#endif
