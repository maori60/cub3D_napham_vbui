/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:59 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:34:58 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int count_map_lines(char **lines, int start) {
    int count = 0;
    while (lines[start] && ft_strchr(lines[start], '1'))
        count++, start++;
    return count;
}

int load_map_data(char **lines, t_data *data, int start) {
    data->mapinfo.height = count_map_lines(lines, start);

    // Allocation de mémoire pour la carte
    data->mapinfo.map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
    if (!data->mapinfo.map)
        return display_error(NULL, "Error: Memory allocation failed for map.", FAILURE);

    // Copie des lignes dans data->mapinfo.map
    for (int i = 0; i < data->mapinfo.height; i++) {
        data->mapinfo.map[i] = ft_strdup(lines[start + i]);
        if (!data->mapinfo.map[i]) {
            for (int j = 0; j < i; j++)
                free(data->mapinfo.map[j]);
            free(data->mapinfo.map);
            return display_error(NULL, "Error: Memory allocation failed for map row.", FAILURE);
        }
    }

    data->mapinfo.map[data->mapinfo.height] = NULL;

    // Appel de la validation des bords de la carte
    if (validate_map_borders(data->mapinfo.map, data->mapinfo.height) == FAILURE)
        return FAILURE;

    return SUCCESS;
}
