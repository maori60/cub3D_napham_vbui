/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:47:32 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 20:52:17 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	trim_file_lines(char **lines)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (lines[i])
	{
		trimmed = ft_strtrim(lines[i], " \n");
		if (!trimmed)
			return (display_error_message(NULL, ERR_MALLOC, FAILURE));
		free(lines[i]);
		lines[i] = trimmed;
		i++;
	}
	return (SUCCESS);
}

int	parse_all_lines(char **file, t_game *data)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (parse_texture_line(file[i], data) == FAILURE)
		{
			free_data(data);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	parse_and_validate_map(t_game *data, int map_start)
{
	if (load_map_data(data->map.file, data, map_start) == FAILURE)
		return (FAILURE);
	if (validate_map_walls(data->map.map,
			data->map.height) == FAILURE)
		return (FAILURE);
	if (validate_map_borders(data->map.map,
			data->map.height) == FAILURE)
		return (FAILURE);
	if (validate_map_characters(data->map.map,
			data->map.height, data->map.width) == FAILURE)
		return (FAILURE);
	if (validate_map_spaces(data->map.map,
			data->map.height, data->map.width) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
