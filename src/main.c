/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 22:47:51 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_game *game)
{
	game->player.plane_x = game->player.dir_y * 0.66;
	game->player.plane_y = -game->player.dir_x * 0.66;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

/**
 * Initializes program data.
 */
void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.03;
}

/**
 * Frees MLX and texture resources before exiting.
 */
void	clean_exit(t_game *data, int exit_code)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_data(data);
	exit(exit_code);
}

/**
 * Program entry point.
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (display_error_message(NULL, ERR_USAGE, FAILURE));
	init_game(&game);
	init_mlx(&game);
	if (load_map_file(argv[1], &game) == FAILURE)
		clean_exit(&game, FAILURE);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	//mlx_hook(game.win, 17, 0, clean_exit, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
}
