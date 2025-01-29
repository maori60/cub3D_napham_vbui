/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:10 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:27:49 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

static int find_player_position(char **map, t_player *player) {
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (ft_strchr("NSEW", map[i][j])) {
                if (player->dir != '\0')
                    return display_error(NULL, "Error: Multiple player positions.", FAILURE);
                player->dir = map[i][j];
                player->pos_x = j + 0.5;
                player->pos_y = i + 0.5;
                map[i][j] = '0';
            }
        }
    }
    if (player->dir == '\0')
        return display_error(NULL, "Error: Missing player position.", FAILURE);
    return SUCCESS;
}

int validate_player_position(t_data *data) {
    if (!data || !data->mapinfo.map)
        return display_error(NULL, "Error: Map data is missing.", FAILURE);

    if (find_player_position(data->mapinfo.map, &data->player) == FAILURE)
        return display_error(NULL, "Error: Invalid player position.", FAILURE);

    return SUCCESS;
}
