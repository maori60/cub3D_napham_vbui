/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:10 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:12:11 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Vérifie si un caractère représente un espace vide.
 */
static int	is_invalid_position(char c)
{
	return (c == ' ' || c == '\0');
}

/**
 * Vérifie si la position du joueur est valide (entouré correctement).
 */
static int	check_player_surroundings(char **map, int x, int y)
{
	if (is_invalid_position(map[y - 1][x]) || is_invalid_position(map[y + 1][x])
		|| is_invalid_position(map[y][x - 1]) || is_invalid_position(map[y][x + 1]))
	{
		return (FAILURE);
	}
	return (SUCCESS);
}

/**
 * Trouve la position du joueur et vérifie qu'il est bien placé.
 */
static int	find_player_position(char **map, t_player *player, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if (player->dir != '\0')
					return (display_error_message(NULL, "Error: Multiple player positions.", FAILURE));
				player->dir = map[i][j];
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				if (check_player_surroundings(map, j, i) == FAILURE)
					return (display_error_message(NULL, "Error: Player position invalid (too close to empty space).", FAILURE));
				map[i][j] = '0'; // Remplace le joueur par '0' après enregistrement
			}
			j++;
		}
		i++;
	}
	return (player->dir == '\0') ? display_error_message(NULL, "Error: Missing player position.", FAILURE) : SUCCESS;
}

/**
 * Valide la position du joueur dans la carte.
 */
int	validate_player_position(t_data *data)
{
	if (!data || !data->mapinfo.map)
		return (display_error_message(NULL, "Error: Map data is missing.", FAILURE));

	if (find_player_position(data->mapinfo.map, &data->player, data->mapinfo.height) == FAILURE)
		return (FAILURE);

	return (SUCCESS);
}
