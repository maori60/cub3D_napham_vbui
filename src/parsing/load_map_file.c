/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:07:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/26 20:41:53 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	open_and_store(char *filepath, t_game *data)
{
	int	fd;
	int	line_count;

	line_count = count_file_lines(filepath);
	if (line_count == FAILURE)
		return (FAILURE);
	data->map.file = malloc(sizeof(char *) * (line_count + 1));
	if (!data->map.file)
		return (display_error_message(NULL, ERR_MALLOC, FAILURE));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		free(data->map.file);
		return (display_error_message(filepath, strerror(errno), FAILURE));
	}
	if (load_file_content(data->map.file, fd) == FAILURE)
		return (close(fd), FAILURE);
	close(fd);
	return (SUCCESS);
}

int	load_map_file(char *filepath, t_game *data)
{
	int	map_start;

	if (open_and_store(filepath, data) == FAILURE)
		return (FAILURE);
	if (trim_file_lines(data->map.file) == FAILURE)
		return (FAILURE);
	if (parse_all_lines(data->map.file, data) == FAILURE)
		return (FAILURE);
	map_start = find_map_start(data->map.file);
	if (map_start == -1)
		return (display_error_message(NULL, ERR_INVALID_MAP, FAILURE));
	return (parse_and_validate_map(data, map_start));
}

int	parse_map_file(char *file_path, t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int		skip;

	skip = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == 'N' && line[i + 1] == 'O' && (line[i + 2] == ' '
				|| line[i + 2] == '\t'))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			map->no_path = strdup(&line[i]);
			if (map->no_path[strlen(map->no_path) - 1] == '\n')
				map->no_path[strlen(map->no_path) - 1] = '\0';
		}
		else if (line[i] == 'S' && line[i + 1] == 'O' && (line[i + 2] == ' '
				|| line[i + 2] == '\t'))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			map->so_path = strdup(&line[i]);
			if (map->so_path[strlen(map->so_path) - 1] == '\n')
				map->so_path[strlen(map->so_path) - 1] = '\0';
		}
		else if (line[i] == 'E' && line[i + 1] == 'A' && (line[i + 2] == ' '
				|| line[i + 2] == '\t'))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			map->ea_path = strdup(&line[i]);
			if (map->ea_path[strlen(map->ea_path) - 1] == '\n')
				map->ea_path[strlen(map->ea_path) - 1] = '\0';
		}
		else if (line[i] == 'W' && line[i + 1] == 'E' && (line[i + 2] == ' '
				|| line[i + 2] == '\t'))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			map->we_path = strdup(&line[i]);
			if (map->we_path[strlen(map->we_path) - 1] == '\n')
				map->we_path[strlen(map->we_path) - 1] = '\0';
		}
		else if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		{
			i++;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			map->floor_color = parse_color(&line[i]);
		}
		else if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		{
			i++;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			map->ceiling_color = parse_color(&line[i]);
		}
		else if (line[i] == '1' || line[i] == '0')
		{
			//todo: parse map
		}
		free(line);
	}
	close(fd);
	return (0);
}
