/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:30:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 20:54:46 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_floor_ceiling_hex(t_texinfo *t)
{
	t->hex_floor = rgb_to_hex(t->floor[0], t->floor[1], t->floor[2]);
	t->hex_ceiling = rgb_to_hex(t->ceiling[0], t->ceiling[1], t->ceiling[2]);
}

void	configure_floor_ceiling_colors(t_texinfo *textures)
{
	if (!textures->floor
		|| !textures->ceiling)
	{
		printf("[ERROR] Couleurs sol ou plafond manquantes\n");
		return ;
	}
	set_floor_ceiling_hex(textures);
	printf("[DEBUG] Sol : 0x%06X\n", textures->hex_floor);
	printf("[DEBUG] Plafond : 0x%06X\n", textures->hex_ceiling);
}
