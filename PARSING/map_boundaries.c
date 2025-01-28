/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:08:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Vérifie que les bords haut et bas de la carte sont correctement fermés.
 */
static int check_horizontal_boundaries(char **map, int row) {
    for (int i = 0; map[row][i]; i++) {
        if (map[row][i] != '1' && map[row][i] != ' ')
            return display_error(NULL, "Error: Top or bottom boundary not closed.", FAILURE);
    }
    return SUCCESS;
}

/**
 * Vérifie que les bords gauche et droit de chaque ligne de la carte sont fermés.
 */
static int check_vertical_boundaries(char **map, int height) {
    for (int i = 1; i < height - 1; i++) {
        if (map[i][0] != '1' && map[i][ft_strlen(map[i]) - 1] != '1')
            return display_error(NULL, "Error: Left or right boundary not closed.", FAILURE);
    }
    return SUCCESS;
}

/**
 * Valide que la carte est entièrement entourée de murs.
 */
int validate_map_boundaries(char **map, int height) {
    if (check_horizontal_boundaries(map, 0) == FAILURE || check_horizontal_boundaries(map, height - 1) == FAILURE)
        return FAILURE;
    if (check_vertical_boundaries(map, height) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
