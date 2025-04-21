/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:10 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:41:49 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_player_position(t_data *data)
{
	if (!data || !data->mapinfo.map)
		return (display_error_message(NULL,
				"Error: Map data is missing.", FAILURE));
	if (find_player_position(data->mapinfo.map,
			&data->player, data->mapinfo.height) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
