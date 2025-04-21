/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:35:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:32:41 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Gère les lignes de textures (NO, SO, WE, EA)
*/
static int	handle_texture_line(char *line, t_texinfo *textures)
{
	char	*path;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->north, path));
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->south, path));
	}
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->west, path));
	}
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->east, path));
	}
	return (SUCCESS);
}

/*
** Redirige selon type (NO, SO, WE, EA, F, C)
*/
int	parse_texture_line(char *line, t_data *data)
{
	t_texinfo	*textures;

	textures = &data->texinfo;
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_rgb_colors(textures, line + 2, 1));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_rgb_colors(textures, line + 2, 0));
	return (handle_texture_line(line, textures));
}
