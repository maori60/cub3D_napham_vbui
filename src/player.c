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

static void	move_forward_backward(t_game *game, double dir)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * game->player.move_speed
		* dir;
	new_y = game->player.pos_y + game->player.dir_y * game->player.move_speed
		* dir;
	if (game->map->map[(int)new_y][(int)new_x] != '1')
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

static void	strafe_left_right(t_game *game, double dir)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.plane_x * game->player.move_speed
		* dir;
	new_y = game->player.pos_y + game->player.plane_y * game->player.move_speed
		* dir;
	if (game->map->map[(int)new_y][(int)new_x] != '1')
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
	}
}

static void	rotate_player(t_game *game, double rot_dir)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = game->player.rot_speed * rot_dir;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y
		* cos(rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y
		* cos(rot_speed);
}

void	move_player(t_game *game)
{
	if (game->keys.w)
		move_forward_backward(game, 1.0);
	if (game->keys.s)
		move_forward_backward(game, -1.0);
	if (game->keys.a)
		strafe_left_right(game, -1.0);
	if (game->keys.d)
		strafe_left_right(game, 1.0);
	if (game->keys.right)
		rotate_player(game, 1.0);
	if (game->keys.left)
		rotate_player(game, -1.0);
	if (game->keys.esc)
		exit_game(game);
}
