/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:14 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:34:16 by vbui             ###   ########.fr       */
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

static int	validate_presence(t_data *data, t_texinfo *textures)
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

int	validate_textures_and_colors(t_data *data, t_texinfo *textures)
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
	data->texinfo.hex_floor = rgb_to_hex(textures->floor[0],
			textures->floor[1], textures->floor[2]);
	data->texinfo.hex_ceiling = rgb_to_hex(textures->ceiling[0],
			textures->ceiling[1], textures->ceiling[2]);
	return (SUCCESS);
}
