/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:14:07 by napham            #+#    #+#             */
/*   Updated: 2025/05/27 23:29:20 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	process_non_empty_line(char *line, t_map *map, int *map_start,
		int line_count)
{
	int	temp_start;

	if (!*map_start)
	{
		temp_start = check_map_start(line, map, line_count);
		if (temp_start)
			*map_start = temp_start;
	}
	return (parse_config_line(line, map));
}

static int	allocate_map(t_map *map)
{
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (-1);
	return (0);
}

int	load_map(char *path, t_map *map)
{
	int	fd;
	int	map_start;
	int	line_count;

	if (!path || !map)
		return (-1);
	fd = open_file(path);
	if (fd < 0)
		return (-1);
	line_count = parse_config(fd, map, &map_start);
	close(fd);
	if (line_count < 0 || validate_config(map, map_start) == -1)
		return (-1);
	map->height = line_count - map_start;
	if (map->height <= 0 || allocate_map(map) == -1)
		return (-1);
	fd = open_file(path);
	if (fd < 0 || skip_to_map(fd, map_start) == -1 || read_map_content(fd,
			map) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
