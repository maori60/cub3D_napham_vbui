/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:05:58 by napham            #+#    #+#             */
/*   Updated: 2025/05/22 20:07:29 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 119)
		game->keys.w = 1;
	else if (keycode == 1 || keycode == 115)
		game->keys.s = 1;
	else if (keycode == 0 || keycode == 97)
		game->keys.a = 1;
	else if (keycode == 2 || keycode == 100)
		game->keys.d = 1;
	else if (keycode == 123 || keycode == 65361)
		game->keys.left = 1;
	else if (keycode == 124 || keycode == 65363)
		game->keys.right = 1;
	else if (keycode == 53 || keycode == 65307)
		game->keys.esc = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 119)
		game->keys.w = 0;
	else if (keycode == 1 || keycode == 115)
		game->keys.s = 0;
	else if (keycode == 0 || keycode == 97)
		game->keys.a = 0;
	else if (keycode == 2 || keycode == 100)
		game->keys.d = 0;
	else if (keycode == 123 || keycode == 65361)
		game->keys.left = 0;
	else if (keycode == 124 || keycode == 65363)
		game->keys.right = 0;
	else if (keycode == 53 || keycode == 65307)
		game->keys.esc = 0;
	return (0);
}
