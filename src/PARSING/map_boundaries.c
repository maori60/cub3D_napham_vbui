/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:07:16 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Vérifie les bords horizontaux (haut et bas de la carte).
 */
static int	check_horizontal_boundaries(char **map, int row)
{
	int	i;

	i = 0;
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' '
			&& !ft_strchr("NSEW", map[row][i]))
			return (display_error_message(NULL, ERR_MAP_NO_WALLS, FAILURE));
		i++;
	}
	return (SUCCESS);
}

/**
 * Vérifie les bords verticaux (gauche et droite de la carte).
 */
static int	check_vertical_boundaries(char **map, int height)
{
	int	i;
	int	len;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len > 0 && (map[i][0] != '1' || map[i][len - 1] != '1'))
			return (display_error_message(NULL, ERR_MAP_NO_WALLS, FAILURE));
		i++;
	}
	return (SUCCESS);
}

/**
 * Fonction principale pour valider les bords de la carte.
 */
int	validate_map_borders(char **map, int height)
{
	if (check_horizontal_boundaries(map, 0) == FAILURE
		|| check_horizontal_boundaries(map, height - 1) == FAILURE)
		return (FAILURE);
	if (check_vertical_boundaries(map, height) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
