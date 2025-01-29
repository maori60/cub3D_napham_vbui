/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:14 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:13:20 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Vérifie que le fichier existe et a l'extension correcte.
 */
static int	validate_xpm_file(char *path)
{
	if (!path || !ft_strnstr(path, ".xpm", ft_strlen(path)))
		return (display_error_message(path, "Error: Texture file must have .xpm extension.", FAILURE));

	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (display_error_message(path, ERR_FILE_NOT_XPM, FAILURE));
	close(fd);
	return (SUCCESS);
}

/**
 * Supprime les espaces au début et à la fin d'un chemin.
 */
static char	*trim_texture_path(char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		display_error_message(NULL, ERR_MALLOC, FAILURE);
	return (trimmed);
}

/**
 * Vérifie et stocke une texture.
 */
static int	store_texture(char **texture, char *path)
{
	if (*texture != NULL)
	{
		free(path);
		return (display_error_message(NULL, "Error: Duplicate texture definition.", FAILURE));
	}
	*texture = path;
	return (SUCCESS);
}

/**
 * Valide toutes les textures et les couleurs.
 */
int	validate_textures_and_colors(t_data *data, t_texinfo *textures)
{
	// Vérification que les données sont valides
	if (!data || !textures)
		return (display_error_message(NULL, "Error: Invalid data or textures.", FAILURE));

	// Vérifier si toutes les textures sont bien définies
	if (!textures->north || !textures->south || !textures->west || !textures->east)
	{
		free_data(data);
		return (display_error_message(NULL, ERR_TEX_MISSING, FAILURE));
	}

	// Vérification que les fichiers XPM existent et sont accessibles
	if (validate_xpm_file(textures->north) == FAILURE ||
		validate_xpm_file(textures->south) == FAILURE ||
		validate_xpm_file(textures->west) == FAILURE ||
		validate_xpm_file(textures->east) == FAILURE)
	{
		free_data(data);
		return (FAILURE);
	}

	// Vérification des couleurs sol/plafond
	if (textures->floor_color == -1 || textures->ceiling_color == -1)
	{
		free_data(data);
		return (display_error_message(NULL, ERR_COLOR_MISSING, FAILURE));
	}

	// Convertir les couleurs RGB en hexadécimal et les stocker
	data->texinfo.hex_floor = rgb_to_hex(textures->floor);
	data->texinfo.hex_ceiling = rgb_to_hex(textures->ceiling);

	return (SUCCESS);
}

/**
 * Parse une ligne de texture ou de couleur.
 */
int	parse_texture_line(char *line, t_data *data)
{
	t_texinfo	*textures;
	char		*path;

	textures = &data->texinfo;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->north, path));
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->south, path));
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->west, path));
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		path = trim_texture_path(line + 3);
		return (store_texture(&textures->east, path));
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		return (parse_rgb_colors(&data->texinfo, line + 2, 1));
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		return (parse_rgb_colors(&data->texinfo, line + 2, 0));
	}
	return (SUCCESS);
}
