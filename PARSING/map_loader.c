/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:59 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:08:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    // Compte le nombre de lignes de la carte à partir de 'start'
    data->mapinfo.height = count_map_lines(lines, start);

    // Allocation de mémoire pour la carte
    data->mapinfo.map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
    if (!data->mapinfo.map)
        return display_error(NULL, "Error: Memory allocation failed for map.", FAILURE);

    // Copie des lignes dans mapinfo.map
    for (int i = 0; i < data->mapinfo.height; i++) {
        data->mapinfo.map[i] = ft_strdup(lines[start + i]);
        if (!data->mapinfo.map[i]) {
            // Libération de la mémoire en cas d'erreur
            for (int j = 0; j < i; j++)
                free(data->mapinfo.map[j]);
            free(data->mapinfo.map);
            return display_error(NULL, "Error: Memory allocation failed for map row.", FAILURE);
        }
    }

    // Ajout du NULL terminal
    data->mapinfo.map[data->mapinfo.height] = NULL;

    return SUCCESS;
}
