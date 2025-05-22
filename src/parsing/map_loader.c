/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:59 by vbui              #+#    #+#             */
/*   Updated: 2025/05/21 23:10:54 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Finds the widest line in the map.
 */
int	find_max_width(char **lines, int start, int height)
{
	int	max_width;
	int	len;
	int	i;

	max_width = 0;
	i = start;
	while (i < start + height)
	{
		len = ft_strlen(lines[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

/**
 * Counts the number of map lines from start.
 */
int	count_map_lines(char **lines, int start)
{
	int	count;

	count = 0;
	while (lines[start] && ft_strchr(lines[start], '1'))
	{
		count++;
		start++;
	}
	return (count);
}

static int	fill_map_line(char *src, char *dst, int width)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (src[j])
	{
		if (src[j] != ' ')
			dst[k++] = src[j];
		j++;
	}
	while (k < width)
		dst[k++] = '1';
	return (SUCCESS);
}

/**
 * Loads the map into memory, trimming spaces and filling with walls.
 */
int	load_map_data(char **lines, t_game *data, int start)
{
	int	i;

	data->mapinfo.height = count_map_lines(lines, start);
	data->mapinfo.width = find_max_width(
			lines, start, data->mapinfo.height);
	data->mapinfo.map = malloc(
			sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->mapinfo.map)
		return (display_error_message(NULL, ERR_MALLOC, FAILURE));
	i = -1;
	while (++i < data->mapinfo.height)
	{
		data->mapinfo.map[i] = ft_calloc(
				data->mapinfo.width + 1, sizeof(char));
		if (!data->mapinfo.map[i])
			return (display_error_message(NULL,
					"Error: Malloc failed for map row.", FAILURE));
		fill_map_line(lines[start + i],
			data->mapinfo.map[i], data->mapinfo.width);
	}
	data->mapinfo.map[data->mapinfo.height] = NULL;
	return (SUCCESS);
}
