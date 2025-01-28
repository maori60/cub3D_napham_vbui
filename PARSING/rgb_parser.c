/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:12 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:08:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Compte le nombre d'éléments dans un tableau de chaînes.
 */
static int array_length(char **array) {
    int length = 0;
    while (array[length])
        length++;
    return length;
}

/**
 * Libère un tableau de chaînes.
 */
static void free_split(char **split) {
    for (int i = 0; split && split[i]; i++)
        free(split[i]);
    free(split);
}

/**
 * Divise une ligne RGB en un tableau d'entiers.
 */
static int *parse_rgb_values(char *line) {
    char **split = ft_split(line, ',');
    if (!split || array_length(split) != 3) {
        free_split(split);
        display_error(NULL, "Error: Invalid RGB format.", FAILURE);
        return NULL;
    }

    int *rgb = malloc(sizeof(int) * 3);
    if (!rgb) {
        free_split(split);
        display_error(NULL, "Error: Memory allocation failed.", FAILURE);
        return NULL;
    }

    for (int i = 0; i < 3; i++) {
        rgb[i] = ft_atoi(split[i]);
        if (rgb[i] < 0 || rgb[i] > 255) {
            free(rgb);
            free_split(split);
            display_error(NULL, "Error: Invalid RGB value.", FAILURE);
            return NULL;
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
