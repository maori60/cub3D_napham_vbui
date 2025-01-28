/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:08:27 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:27:35 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

/**
 * Initialise les structures de données.
 */
void init_data(t_data *data) {
    data->mapinfo.file = NULL;
    data->mapinfo.map = NULL;
    data->mapinfo.width = 0;
    data->mapinfo.height = 0;

    data->texinfo.north = NULL;
    data->texinfo.south = NULL;
    data->texinfo.west = NULL;
    data->texinfo.east = NULL;
    data->texinfo.floor = NULL;
    data->texinfo.ceiling = NULL;
    data->texinfo.hex_floor = 0;
    data->texinfo.hex_ceiling = 0;

    data->player.pos_x = 0;
    data->player.pos_y = 0;
    data->player.dir = '\0';
}

/**
 * Libère toutes les ressources allouées.
 */
void free_data(t_data *data) {
    if (data->mapinfo.file) {
        for (int i = 0; data->mapinfo.file[i]; i++)
            free(data->mapinfo.file[i]);
        free(data->mapinfo.file);
    }

    if (data->mapinfo.map) {
        for (int i = 0; data->mapinfo.map[i]; i++)
            free(data->mapinfo.map[i]);
        free(data->mapinfo.map);
    }

    free(data->texinfo.floor);
    free(data->texinfo.ceiling);
}

int main(int argc, char **argv) {
    t_data data;

    init_data(&data);

    if (argc != 2) {
        display_error(NULL, "Usage: ./cub3D <map.cub>", FAILURE);
        return FAILURE;
    }

    if (validate_file_path(argv[1], 1) == FAILURE)
        return FAILURE;

    if (load_map_file(argv[1], &data) == FAILURE) {
        free_data(&data);
        return FAILURE;
    }

    if (validate_textures_and_colors(&data, &data.texinfo) == FAILURE) {
        free_data(&data);
        return FAILURE;
    }

    if (validate_player_position(&data) == FAILURE) {
        free_data(&data);
        return FAILURE;
    }

    printf("Parsing réussi !\n");
    free_data(&data);
    return SUCCESS;
}
