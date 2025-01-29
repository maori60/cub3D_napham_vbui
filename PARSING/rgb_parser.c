/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:12 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:26:21 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int array_length(char **array) {
    int length = 0;
    while (array[length])
        length++;
    return length;
}

static void free_split(char **split) {
    for (int i = 0; split && split[i]; i++)
        free(split[i]);
    free(split);
}

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

int parse_rgb_colors(t_texinfo *textures, char *line, int is_floor) {
    int *rgb = parse_rgb_values(line);
    if (!rgb)
        return FAILURE;

    if (is_floor) {
        free(textures->floor);
        textures->floor = rgb;
    } else {
        free(textures->ceiling);
        textures->ceiling = rgb;
    }

    return SUCCESS;
}
