#include "../includes/cub3d.h"

/**
 * Analyse chaque ligne pour identifier la carte.
 */
static int parse_map_lines(char **lines, t_data *data, int start) {
    data->mapinfo.height = count_lines(lines, start);
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
