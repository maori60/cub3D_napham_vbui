/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:18:33 by napham            #+#    #+#             */
/*   Updated: 2025/05/27 23:29:04 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_config_line(char *line, t_map *map)
{
	if (parse_no_texture(line, map) == -1)
		return (-1);
	if (parse_so_texture(line, map) == -1)
		return (-1);
	if (parse_ea_texture(line, map) == -1)
		return (-1);
	if (parse_we_texture(line, map) == -1)
		return (-1);
	if (parse_floor_color(line, map) == -1)
		return (-1);
	if (parse_ceiling_color(line, map) == -1)
		return (-1);
	return (0);
}
