/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:05:58 by vbui              #+#    #+#             */
/*   Updated: 2025/05/24 07:42:20 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <X11/keysym.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = 1;
	else if (keycode == XK_s)
		game->keys.s = 1;
	else if (keycode == XK_a)
		game->keys.a = 1;
	else if (keycode == XK_d)
		game->keys.d = 1;
	else if (keycode == XK_Left)
		game->keys.left = 1;
	else if (keycode == XK_Right)
		game->keys.right = 1;
	else if (keycode == XK_Escape)
		game->keys.esc = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = 0;
	else if (keycode == XK_s)
		game->keys.s = 0;
	else if (keycode == XK_a)
		game->keys.a = 0;
	else if (keycode == XK_d)
		game->keys.d = 0;
	else if (keycode == XK_Left)
		game->keys.left = 0;
	else if (keycode == XK_Right)
		game->keys.right = 0;
	else if (keycode == XK_Escape)
		game->keys.esc = 0;
	return (0);
}
