/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:15:26 by napham            #+#    #+#             */
/*   Updated: 2025/05/27 23:57:39 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	validate_config(t_map *map, int map_start)
{
	if (!map->no_path || !map->so_path || !map->ea_path || !map->we_path
		|| map_start == 0)
		return (-1);
	return (0);
}

static int	skip_to_map(int fd, int map_start)
{
	char	*line;
	int		i;

	i = 0;
	while (i < map_start)
	{
		line = get_next_line(fd);
		if (!line)
			return (-1);
		free(line);
		i++;
	}
	return (0);
}

static char	*copy_map_line(char *line)
{
	char	*map_line;
	int		j;

	j = 0;
	while (line[j] && line[j] != '\n')
		j++;
	map_line = malloc(j + 1);
	if (!map_line)
		return (NULL);
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		map_line[j] = line[j];
		j++;
	}
	map_line[j] = '\0';
	return (map_line);
}

static int	read_map_content(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (-1);
		map->map[i] = copy_map_line(line);
		if (!map->map[i])
		{
			free(line);
			return (-1);
		}
		if (map->width < ft_strlen(map->map[i]))
			map->width = ft_strlen(map->map[i]);
		free(line);
		i++;
	}
	map->map[i] = NULL;
	return (0);
}

static int	parse_config(int fd, t_map *map, int *map_start)
{
	char	*line;
	int		line_count;

	line_count = 0;
	*map_start = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!is_empty_line(line))
		{
			if (process_non_empty_line(line, map, map_start, line_count) == -1)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
		line_count++;
	}
	return (line_count);
}
