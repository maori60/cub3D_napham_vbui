#include "../includes/cub3d.h"

/**
 * Divise une ligne RGB en un tableau d'entiers.
 */
static int *parse_rgb_values(char *line) {
    char **split = ft_split(line, ',');
    if (!split || ft_array_length(split) != 3)
        return display_error(NULL, "Error: Invalid RGB format.", NULL);
    int *rgb = malloc(sizeof(int) * 3);
    if (!rgb)
        return display_error(NULL, "Error: Memory allocation failed.", NULL);
    for (int i = 0; i < 3; i++) {
        rgb[i] = ft_atoi(split[i]);
        if (rgb[i] < 0 || rgb[i] > 255) {
            free(rgb);
            free_split(split);
            return display_error(NULL, "Error: Invalid RGB value.", NULL);
        }
    }
    free_split(split);
    return rgb;
}

/**
 * Analyse les couleurs RGB pour le sol et le plafond.
 */
int parse_rgb_colors(t_data *data, char *line, int is_floor) {
    int *rgb = parse_rgb_values(line);
    if (!rgb)
        return FAILURE;
    if (is_floor)
        data->texinfo.floor = rgb;
    else
        data->texinfo.ceiling = rgb;
    return SUCCESS;
}
