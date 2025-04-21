/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:16:32 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:24:01 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_mapinfo(t_mapinfo *m)
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

static void	free_texinfo(t_texinfo *t)
{
	if (t->north)
		free(t->north);
	if (t->south)
		free(t->south);
	if (t->west)
		free(t->west);
	if (t->east)
		free(t->east);
	if (t->floor)
		free(t->floor);
	if (t->ceiling)
		free(t->ceiling);
	t->north = NULL;
	t->south = NULL;
	t->west = NULL;
	t->east = NULL;
	t->floor = NULL;
	t->ceiling = NULL;
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_mapinfo(&data->mapinfo);
	free_texinfo(&data->texinfo);
}
