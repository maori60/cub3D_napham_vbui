/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:51:30 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int check_horizontal_boundaries(char **map, int row) {
    for (int i = 0; map[row][i]; i++) {
        if (map[row][i] != '1' && map[row][i] != ' ')
            return display_error(NULL, "Error: Top or bottom boundary not closed.", FAILURE);
    }
    return SUCCESS;
}

static int check_vertical_boundaries(char **map, int height) {
    for (int i = 1; i < height - 1; i++) {
        if (map[i][0] != '1' && map[i][ft_strlen(map[i]) - 1] != '1')
            return display_error(NULL, "Error: Left or right boundary not closed.", FAILURE);
    }
    return SUCCESS;
}

int validate_map_boundaries(char **map, int height) {
    if (check_horizontal_boundaries(map, 0) == FAILURE || check_horizontal_boundaries(map, height - 1) == FAILURE)
        return FAILURE;
    if (check_vertical_boundaries(map, height) == FAILURE)
        return FAILURE;
    return SUCCESS;
}


/**
 * Vérifie que les bords de la carte sont entourés de '1' (murs).
 * Les bords comprennent le haut, le bas, la gauche et la droite.
 */
int validate_map_borders(char **map, int height) {
    // Vérification des bords horizontalement
    for (size_t i = 0; i < ft_strlen(map[0]); i++) {
        if (map[0][i] != '1') {
            return display_error(NULL, "Error: Top boundary not closed.", FAILURE);
        }
    }
    for (size_t i = 0; i < ft_strlen(map[height - 1]); i++) {
        if (map[height - 1][i] != '1') {
            return display_error(NULL, "Error: Bottom boundary not closed.", FAILURE);
        }
    }

    // Vérification des bords verticalement
    for (int i = 1; i < height - 1; i++) {
        if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1') {
            return display_error(NULL, "Error: Left or right boundary not closed.", FAILURE);
        }
    }

    return SUCCESS;
}

#include "../includes/cub3d.h"

static int check_top_or_bottom(char **map_tab, int i, int j)
{
    if (!map_tab || !map_tab[i] || !map_tab[i][j])
        return (FAILURE);
    while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t'
    || map_tab[i][j] == '\r' || map_tab[i][j] == '\v'
    || map_tab[i][j] == '\f')
        j++;
    while (map_tab[i][j])
    {
        if (map_tab[i][j] != '1')
            return (FAILURE);
        j++;
    }
    return (SUCCESS);
}

int check_map_borders(t_mapinfo *map, char **map_tab)
{
    int i;
    int j;

    // Vérification du bord supérieur
    if (check_top_or_bottom(map_tab, 0, 0) == FAILURE)  // Bord supérieur
        return (FAILURE);

    // Vérification du bord gauche et droit
    i = 1;
    while (i < (map->height - 1))
    {
        j = ft_strlen(map_tab[i]) - 1;
        if (map_tab[i][j] != '1')
            return (FAILURE);
        i++;
    }

    // Vérification du bord inférieur
    if (check_top_or_bottom(map_tab, i, 0) == FAILURE)  // Bord inférieur
        return (FAILURE);

    return (SUCCESS);
}
