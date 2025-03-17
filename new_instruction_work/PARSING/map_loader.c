/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:07:59 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:09:36 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Trouve la plus grande largeur de ligne dans la carte.
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
 * Compte le nombre de lignes de la carte à partir du point de départ.
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

/**
 * Charge les données de la carte en supprimant les espaces.
 */
int	load_map_data(char **lines, t_data *data, int start)
{
	int	i;
	int	j;
	int	k;

	data->mapinfo.height = count_map_lines(lines, start);
	data->mapinfo.width = find_max_width(lines, start, data->mapinfo.height);
	data->mapinfo.map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->mapinfo.map)
		return (display_error_message(NULL, ERR_MALLOC, FAILURE));
	i = 0;
	while (i < data->mapinfo.height)
	{
		data->mapinfo.map[i] = ft_calloc(data->mapinfo.width + 1, sizeof(char));
		if (!data->mapinfo.map[i])
			return (display_error_message(NULL, "Error: Memory allocation failed for map row.", FAILURE));
		k = 0;
		j = -1;
		while (lines[start + i][++j])
			if (lines[start + i][j] != ' ')
				data->mapinfo.map[i][k++] = lines[start + i][j];
		while (k < data->mapinfo.width)
			data->mapinfo.map[i][k++] = '1';
		i++;
	}
	data->mapinfo.map[data->mapinfo.height] = NULL;
	return (SUCCESS);
}
