/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:43:25 by napham            #+#    #+#             */
/*   Updated: 2025/05/24 10:03:48 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_game *game)
{
	double  new_x;
	double  new_y;
	double  old_dir_x;
	double  old_plane_x;

	if (game->keys.w)
	{
		new_x = game->player.pos_x + game->player.dir_x
			* game->player.move_speed;
		new_y = game->player.pos_y + game->player.dir_y
			* game->player.move_speed;
		if (game->map.map[(int)new_y][(int)new_x] != '1')
		{
			game->player.pos_x = new_x;
			game->player.pos_y = new_y;
		}
	}
	if (game->keys.s)
	{
		new_x = game->player.pos_x - game->player.dir_x
			* game->player.move_speed;
		new_y = game->player.pos_y - game->player.dir_y
			* game->player.move_speed;
		if (game->map.map[(int)new_y][(int)new_x] != '1')
		{
			game->player.pos_x = new_x;
			game->player.pos_y = new_y;
		}
	}
	if (game->keys.a)
	{
		new_x = game->player.pos_x - game->player.plane_x
			* game->player.move_speed;
		new_y = game->player.pos_y - game->player.plane_y
			* game->player.move_speed;
		if (game->map.map[(int)new_y][(int)new_x] != '1')
		{
			game->player.pos_x = new_x;
			game->player.pos_y = new_y;
		}
	}
	if (game->keys.d)
	{
		new_x = game->player.pos_x + game->player.plane_x
			* game->player.move_speed;
		new_y = game->player.pos_y + game->player.plane_y
			* game->player.move_speed;
		if (game->map.map[(int)new_y][(int)new_x] != '1')
		{
			game->player.pos_x = new_x;
			game->player.pos_y = new_y;
		}
	}
	if (game->keys.right)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-game->player.rot_speed)
			- game->player.dir_y * sin(-game->player.rot_speed);
		game->player.dir_y = old_dir_x * sin(-game->player.rot_speed)
			+ game->player.dir_y * cos(-game->player.rot_speed);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x
			* cos(-game->player.rot_speed) - game->player.plane_y
			* sin(-game->player.rot_speed);
		game->player.plane_y = old_plane_x * sin(-game->player.rot_speed)
			+ game->player.plane_y * cos(-game->player.rot_speed);
	}
	if (game->keys.left)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(game->player.rot_speed)
			- game->player.dir_y * sin(game->player.rot_speed);
		game->player.dir_y = old_dir_x * sin(game->player.rot_speed)
			+ game->player.dir_y * cos(game->player.rot_speed);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x
			* cos(game->player.rot_speed) - game->player.plane_y
			* sin(game->player.rot_speed);
		game->player.plane_y = old_plane_x * sin(game->player.rot_speed)
			+ game->player.plane_y * cos(game->player.rot_speed);
	}
	/*
		if (game->keys.esc)
		exit_game(game);
	*/
}