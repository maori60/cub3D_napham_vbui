/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:15:52 by napham            #+#    #+#             */
/*   Updated: 2025/05/27 23:28:18 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_map_start(char *line, t_map *map, int line_count)
{
	int	i;
	int	j;

	i = skip_whitespace(line);
	if (!is_map_char(line[i]))
		return (0);
	j = i;
	while (line[j] && line[j] != '\n')
	{
		if (!is_map_char(line[j]))
			return (0);
		j++;
	}
	map->width = 0;
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		map->width++;
		j++;
	}
	return (line_count);
}

static char	*extract_path(char *line, int start)
{
	char	*path;
	int		i;
	int		j;
	int		len;

	i = start;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	if (j <= i)
		return (NULL);
	len = j - i;
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	j = 0;
	while (line[i] && line[i] != '\n')
		path[j++] = line[i++];
	path[j] = '\0';
	return (path);
}

static int	parse_texture(char *line, char **texture_path, int offset)
{
	char	*path;

	path = extract_path(line, offset);
	if (!path)
		return (-1);
	*texture_path = path;
	return (0);
}

static int	parse_no_texture(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		return (parse_texture(line, &map->no_path, i + 2));
	return (1);
}

static int	parse_so_texture(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		return (parse_texture(line, &map->so_path, i + 2));
	return (1);
}
