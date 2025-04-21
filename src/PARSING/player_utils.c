/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:49:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:59:14 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_invalid_position(char c)
{
	return (c == ' ' || c == '\0');
}

int	check_player_surroundings(char **map, int x, int y)
{
	if (is_invalid_position(map[y - 1][x])
		|| is_invalid_position(map[y + 1][x])
		|| is_invalid_position(map[y][x - 1])
		|| is_invalid_position(map[y][x + 1]))
		return (FAILURE);
	return (SUCCESS);
}

int	multiple_players(t_player *player)
{
	return (player->dir != '\0');
}

int	player_not_found(t_player *player)
{
	if (player->dir == '\0')
		return (display_error_message(NULL,
				"Error: Missing player position.", FAILURE));
	return (SUCCESS);
}

int	handle_player(char **map, int i, int j, t_player *player)
{
	player->dir = map[i][j];
	player->pos_x = j + 0.5;
	player->pos_y = i + 0.5;
	if (check_player_surroundings(map, j, i) == FAILURE)
		return (display_error_message(NULL,
				"Error: Player too close to empty space.", FAILURE));
	map[i][j] = '0';
	return (SUCCESS);
}
