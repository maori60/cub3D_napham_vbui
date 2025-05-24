/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:35:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 20:44:15 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_color(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(line, ',');
	if (!rgb)
		return (0);
	r = atoi(rgb[0]);
	g = atoi(rgb[1]);
	b = atoi(rgb[2]);
	free_split(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return ((r << 16) | (g << 8) | b);
}

/*
** Gère les lignes de textures (NO, SO, WE, EA)
*/
static int	handle_texture_line(char *line, t_game *game)
{
	char	*path;
	int		w;
	int		h;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		game->textures.north = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		game->textures.south = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	}
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		game->textures.west = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	}
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		game->textures.east = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	}
	return (SUCCESS);
}

/*
** Redirige selon type (NO, SO, WE, EA, F, C)
*/
int	parse_texture_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		game->textures.floor_color = parse_color(line + 2);
		return (0);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		game->textures.ceiling_color = parse_color(line + 2);
		return (0);
	}
	return (handle_texture_line(line, game));
}
