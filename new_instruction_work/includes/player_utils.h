/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 07:10:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:01:08 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_UTILS_H
# define PLAYER_UTILS_H

# include "cub3d.h"

int	is_invalid_position(char c);
int	check_player_surroundings(char **map, int x, int y);
int	multiple_players(t_player *player);
int	player_not_found(t_player *player);
int	handle_player(char **map, int i, int j, t_player *player);

#endif
