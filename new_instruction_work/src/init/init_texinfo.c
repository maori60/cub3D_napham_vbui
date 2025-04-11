/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 08:10:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:03:55 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_texinfo(t_texinfo *t)
{
	t->north = NULL;
	t->south = NULL;
	t->west = NULL;
	t->east = NULL;
	t->floor = NULL;
	t->ceiling = NULL;
	t->hex_floor = 0x0;
	t->hex_ceiling = 0x0;
}
