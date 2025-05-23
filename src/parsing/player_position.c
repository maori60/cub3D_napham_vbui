/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:10 by vbui              #+#    #+#             */
/*   Updated: 2025/05/21 23:10:54 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_player_position(t_game *data)
{
	if (!data || !data->map.map)
		return (display_error_message(NULL,
				"Error: Map data is missing.", FAILURE));
	if (find_player_position(data->map.map,
			&data->player, data->map.height) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
