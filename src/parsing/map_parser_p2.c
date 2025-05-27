/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:16:25 by napham            #+#    #+#             */
/*   Updated: 2025/05/27 23:28:42 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_ea_texture(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		return (parse_texture(line, &map->ea_path, i + 2));
	return (1);
}

static int	parse_we_texture(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		return (parse_texture(line, &map->we_path, i + 2));
	return (1);
}

static int	parse_floor_color(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] == 'F' && ft_isspace(line[i + 1]))
	{
		i++;
		while (ft_isspace(line[i]))
			i++;
		map->floor_color = parse_color(line + i);
		if (map->floor_color < 0)
			return (-1);
		return (0);
	}
	return (1);
}

static int	parse_ceiling_color(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (line[i] == 'C' && ft_isspace(line[i + 1]))
	{
		i++;
		while (ft_isspace(line[i]))
			i++;
		map->ceiling_color = parse_color(line + i);
		if (map->ceiling_color < 0)
			return (-1);
		return (0);
	}
	return (1);
}
