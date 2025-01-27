#include "../includes/cub3d.h"

/**
 * Vérifie que la carte est entourée de murs.
 */
int validate_map_walls(char **map, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; map[i][j]; j++) {
            if ((i == 0 || i == height - 1 || j == 0 || map[i][j + 1] == '\0') && map[i][j] != '1')
                return display_error(NULL, "Error: Map not enclosed by walls.", FAILURE);
        }
    }
    return SUCCESS;
}
