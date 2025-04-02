/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:48 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:16:22 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Compte le nombre de lignes dans un fichier.
 */
int	count_file_lines(char *filepath)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (display_error_message(filepath, strerror(errno), FAILURE));

	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

/**
 * Charge tout le contenu du fichier dans un tableau.
 */
int	load_file_content(char **content, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		content[i++] = ft_strdup(line);
		if (!content[i - 1])
		{
			while (i-- > 0)
				free(content[i]);
			free(content);
			free(line);
			return (display_error_message(NULL, ERR_MALLOC, FAILURE));
		}
		free(line);
		line = get_next_line(fd);
	}
	content[i] = NULL;
	return (SUCCESS);
}

/**
 * Charge le fichier de la map et vérifie la syntaxe.
 */
int	load_map_file(char *filepath, t_data *data)
{
	int	line_count;
	int	fd;
	int	map_start;

	line_count = count_file_lines(filepath);
	if (line_count == FAILURE)
		return (FAILURE);

	data->mapinfo.file = malloc(sizeof(char *) * (line_count + 1));
	if (!data->mapinfo.file)
		return (display_error_message(NULL, ERR_MALLOC, FAILURE));

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		free(data->mapinfo.file);
		return (display_error_message(filepath, strerror(errno), FAILURE));
	}

	if (load_file_content(data->mapinfo.file, fd) == FAILURE)
	{
		close(fd);
		free(data->mapinfo.file);
		return (FAILURE);
	}
	close(fd);

	// Nettoyage des lignes pour supprimer les espaces inutiles
	int i = 0;
	while (data->mapinfo.file[i])
	{
		char *trimmed = ft_strtrim(data->mapinfo.file[i], " \n");
		if (!trimmed)
			return (display_error_message(NULL, ERR_MALLOC, FAILURE));
		free(data->mapinfo.file[i]);
		data->mapinfo.file[i] = trimmed;
		i++;
	}

	i = 0;
	while (data->mapinfo.file[i])
	{
		if (parse_texture_line(data->mapinfo.file[i], data) == FAILURE)
		{
			free_data(data);
			return (FAILURE);
		}
		i++;
	}

	map_start = find_map_start(data->mapinfo.file);
	if (map_start == -1)
		return (display_error_message(NULL, ERR_INVALID_MAP, FAILURE));

	if (load_map_data(data->mapinfo.file, data, map_start) == FAILURE)
		return (FAILURE);

	if (validate_map_walls(data->mapinfo.map, data->mapinfo.height) == FAILURE)
		return (FAILURE);

	if (validate_map_borders(data->mapinfo.map, data->mapinfo.height) == FAILURE)
		return (FAILURE);

	if (validate_map_characters(data->mapinfo.map, data->mapinfo.height,
			data->mapinfo.width) == FAILURE)
		return (FAILURE);

	if (validate_map_spaces(data->mapinfo.map, data->mapinfo.height,
			data->mapinfo.width) == FAILURE)
		return (FAILURE);

	if (validate_floor_and_ceiling(&data->texinfo) == FAILURE)
		return (FAILURE);

	return (SUCCESS);
}
