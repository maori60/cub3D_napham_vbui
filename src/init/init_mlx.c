/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 21:08:31 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Initialize the MLX connection and create a window.
 */
void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(game, err_msg("mlx", ERR_MLX_START, 1));
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!game->win)
		clean_exit(game, err_msg("mlx", ERR_MLX_WIN, 1));
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		clean_exit(game, err_msg("mlx", "bla", 1));
}
