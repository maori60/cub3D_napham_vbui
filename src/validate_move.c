/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:43:25 by vbui              #+#    #+#             */
/*   Updated: 2025/05/30 22:42:49 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_valid_pos_wall_collision(t_map *map, double x, double y)
{
	if (map->map[(int)y][(int)x] != '1')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_map *map, double x, double y)
{
	if (x < 0.25 || x >= map->width - 1.25)
		return (false);
	if (y < 0.25 || y >= map->height - 0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_map *map, double x, double y)
{
	if (!BONUS && is_valid_pos_in_map(map, x, y))
		return (true);
	if (BONUS && is_valid_pos_wall_collision(map, x, y))
		return (true);
	return (false);
}

void	validate_move(t_game *game, double new_x, double new_y)
{
	if (is_valid_pos(game->map, new_x, game->player.pos_y)
		&& is_valid_pos(game->map, game->player.pos_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}
