/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:45:05 by vbui              #+#    #+#             */
/*   Updated: 2025/05/30 22:56:41 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		free_game(t_game *game);

static void	set_player_direction(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (orientation == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (orientation == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (orientation == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

static void	init_player(t_game *game)
{
	game->player.pos_x = game->map->player_x + 0.5;
	game->player.pos_y = game->map->player_y + 0.5;
	set_player_direction(&game->player, game->map->player_orientation);
	game->player.plane_x = game->player.dir_y * -0.66;
	game->player.plane_y = game->player.dir_x * 0.66;
	game->player.move_speed = 0.0125;
	game->player.rot_speed = 0.015;
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
