/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:16:32 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 20:53:06 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_mapinfo(t_map *m)
{
	int	i;

	if (m->file)
	{
		i = 0;
		while (m->file[i])
			free(m->file[i++]);
		free(m->file);
	}
	if (m->map)
	{
		i = 0;
		while (m->map[i])
			free(m->map[i++]);
		free(m->map);
	}
	m->file = NULL;
	m->map = NULL;
}

void	free_data(t_game *data)
{
	if (!data)
		return ;
	free_mapinfo(&data->map);
}
