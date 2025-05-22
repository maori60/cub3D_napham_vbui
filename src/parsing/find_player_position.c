/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 05:18:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 21:00:43 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/player_utils.h"

int	find_player_position(char **map, t_player *player, int height)
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
				// todo: multiple players
				if (handle_player(map, i, j, player) == FAILURE)
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (-1);
}
