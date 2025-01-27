#include "../includes/cub3d.h"

/**
 * Compte le nombre de lignes valides pour la carte à partir d'un indice donné.
 */
static int count_map_lines(char **lines, int start) {
    int count = 0;
    while (lines[start] && ft_strchr(lines[start], '1'))
        count++, start++;
    return count;
}

/**
 * Charge les lignes de la carte dans un tableau.
 */
int load_map_data(char **lines, t_data *data, int start) {
    data->mapinfo.height = count_map_lines(lines, start);
    data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
    if (!data->map)
        return display_error(NULL, "Error: Memory allocation failed.", FAILURE);
    for (int i = 0; i < data->mapinfo.height; i++) {
        data->map[i] = ft_strdup(lines[start + i]);
        if (!data->map[i])
            return display_error(NULL, "Error: Memory allocation failed.", FAILURE);
    }
    data->map[data->mapinfo.height] = NULL;
    return SUCCESS;
}
