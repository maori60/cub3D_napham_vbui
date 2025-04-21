/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 05:18:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:01:08 by vbui             ###   ########.fr       */
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
				if (multiple_players(player))
					return (display_error_message(NULL,
							"Error: Multiple player positions.", FAILURE));
				if (handle_player(map, i, j, player) == FAILURE)
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (player_not_found(player));
}
