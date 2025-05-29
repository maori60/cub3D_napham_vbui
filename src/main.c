/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/29 20:34:02 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_game(t_game *game);

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (err_msg("mlx", ERR_MLX_WIN), free_game(game));
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		return (err_msg("mlx", ERR_MLX_IMG), free_game(game));
}

void	init_player(t_game *game)
{
	game->player.pos_x = game->map->player_x;
	game->player.pos_y = game->map->player_y;
	if (game->map->player_orientation == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map->player_orientation == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map->player_orientation == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->map->player_orientation == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	game->player.plane_x = game->player.dir_y * 0.66;
	game->player.plane_y = -game->player.dir_x * 0.66;
	game->player.move_speed = 0.005;
	game->player.rot_speed = 0.003;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

void	init_game(t_game *game)
{
	int	w;
	int	h;

	game->textures.north = mlx_xpm_file_to_image(game->mlx, game->map->no_path,
			&w, &h);
	if (!game->textures.north)
		return (err_msg("mlx", ERR_MLX_IMG_LOAD_FAIL), free_game(game));
	game->textures.south = mlx_xpm_file_to_image(game->mlx, game->map->so_path,
			&w, &h);
	if (!game->textures.south)
		return (err_msg("mlx", ERR_MLX_IMG_LOAD_FAIL), free_game(game));
	game->textures.east = mlx_xpm_file_to_image(game->mlx, game->map->ea_path,
			&w, &h);
	if (!game->textures.east)
		return (err_msg("mlx", ERR_MLX_IMG_LOAD_FAIL), free_game(game));
	game->textures.west = mlx_xpm_file_to_image(game->mlx, game->map->we_path,
			&w, &h);
	if (!game->textures.west)
		return (err_msg("mlx", ERR_MLX_IMG_LOAD_FAIL), free_game(game));
	init_player(game);
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
	ft_memset(&game, 0, sizeof(t_game));
	game.map = load_map(argv[1]);
	if (!game.map)
		return (err_msg(NULL, ERR_MAP_LOAD), 1);
	init_mlx(&game);
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
}
