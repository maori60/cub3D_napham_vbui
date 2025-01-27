#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "libft.h"  // A ajouter

// Macros
# define SUCCESS 0
# define FAILURE 1

// Structure pour les textures et couleurs
typedef struct s_texinfo {
    char *north;
    char *south;
    char *west;
    char *east;
    int  *floor;     // Tableau RGB pour le sol
    int  *ceiling;   // Tableau RGB pour le plafond
    unsigned long hex_floor;
    unsigned long hex_ceiling;
} t_texinfo;

// Structure pour la position du joueur
typedef struct s_player {
    double pos_x;  // Position X
    double pos_y;  // Position Y
    char   dir;    // Direction initiale ('N', 'S', 'E', 'W')
} t_player;

// Structure pour la carte
typedef struct s_mapinfo {
    char **file;    // Toutes les lignes du fichier .cub
    char **map;     // Tableau représentant la carte
    int    width;   // Largeur maximale de la carte
    int    height;  // Hauteur de la carte
} t_mapinfo;

// Structure principale pour les données du programme
typedef struct s_data {
    t_mapinfo mapinfo;
    t_texinfo texinfo;
    t_player  player;
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
int parse_rgb_colors(t_data *data, char *line, int is_floor);

// Outils génériques
int display_error(char *context, char *message, int return_code);

#endif
