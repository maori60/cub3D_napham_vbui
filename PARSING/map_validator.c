/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:08 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:45:33 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


/**
 * Valide les caractères présents dans la carte (doivent être seulement 0, 1, N, S, E, W).
 */
int validate_map_characters(char **map, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = map[i][j];
            if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ') {
                return display_error(NULL, "Error: Invalid character in map.", FAILURE);
            }
        }
    }
    return SUCCESS;
}

/**
 * Valide les espaces dans la carte, vérifie que les espaces ne sont pas adjacents à des 0.
 */
int validate_map_spaces(char **map, int height, int width) {
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if (map[i][j] == ' ' &&
                (map[i-1][j] == '0' || map[i+1][j] == '0' || map[i][j-1] == '0' || map[i][j+1] == '0')) {
                return display_error(NULL, "Error: Space is adjacent to 0.", FAILURE);
            }
        }
    }
    return SUCCESS;
}

/**
 * Valide le sol et le plafond (pas d'erreur sur les couleurs).
 */
int validate_floor_and_ceiling(t_texinfo *textures) {
    if (!textures->floor || !textures->ceiling) {
        return display_error(NULL, "Error: Missing floor or ceiling color.", FAILURE);
    }
    return SUCCESS;
}
