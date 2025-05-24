/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:14 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 20:34:58 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	validate_xpm_file(char *path)
{
	int	fd;

	if (!path || !ft_strnstr(path, ".xpm", ft_strlen(path)))
		return (display_error_message(path,
				"Error: Texture file must have .xpm extension.",
				FAILURE));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (display_error_message(path, ERR_FILE_NOT_XPM, FAILURE));
	close(fd);
	return (SUCCESS);
}

static int	validate_texture_paths(t_texinfo *textures)
{
	if (validate_xpm_file(textures->north) == FAILURE
		|| validate_xpm_file(textures->south) == FAILURE
		|| validate_xpm_file(textures->west) == FAILURE
		|| validate_xpm_file(textures->east) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	validate_presence(t_game *data, t_texinfo *textures)
{
	if (!textures->north || !textures->south
		|| !textures->west || !textures->east)
	{
		free_data(data);
		return (display_error_message(NULL, ERR_TEX_MISSING, FAILURE));
	}
	if (textures->floor_color == -1 || textures->ceiling_color == -1)
	{
		free_data(data);
		return (display_error_message(NULL,
				ERR_COLOR_MISSING, FAILURE));
	}
	return (SUCCESS);
}

int	validate_textures_and_colors(t_game *data, t_texinfo *textures)
{
	if (!data || !textures)
		return (display_error_message(NULL,
				"Error: Invalid data or textures.", FAILURE));
	if (validate_presence(data, textures) == FAILURE)
		return (FAILURE);
	if (validate_texture_paths(textures) == FAILURE)
	{
		free_data(data);
		return (FAILURE);
	}
	return (SUCCESS);
}
