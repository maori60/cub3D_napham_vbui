/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/31 00:36:40 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_game(t_game *game);
void	init_game(t_game *game);
bool	str_endswith(const char *str, const char *suffix);

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (err_msg("mlx", ERR_MLX_WIN), free_game(game), 0);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
		return (err_msg("mlx", ERR_MLX_WIN), free_game(game), 0);
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		return (err_msg("mlx", ERR_MLX_IMG), free_game(game), 0);
	return (1);
}

void	free_game(t_game *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->textures.north)
		mlx_destroy_image(game->mlx, game->textures.north);
	if (game->textures.south)
		mlx_destroy_image(game->mlx, game->textures.south);
	if (game->textures.east)
		mlx_destroy_image(game->mlx, game->textures.east);
	if (game->textures.west)
		mlx_destroy_image(game->mlx, game->textures.west);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	free(game->map);
}

int	exit_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (err_msg(NULL, ERR_USAGE), 1);
	if (!str_endswith(argv[1], ".cub"))
		return (err_msg(NULL, "Map file must have .cub extension"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	game.map = load_map(argv[1]);
	if (!game.map)
		return (1);
	if (!init_mlx(&game))
		return (1);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
}
