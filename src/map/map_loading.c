/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:29:57 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 19:40:44 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	get_map_height(char *path, t_map *m)
{
	int	fd;
	int	height;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = count_map_lines(fd, m);
	close(fd);
	return (height);
}

int	allocate_map(t_map *m)
{
	m->map = malloc(sizeof(char *) * m->height);
	if (!m->map)
		return (0);
	return (1);
}

void	reset_map_data(t_map *m)
{
	m->element_count = 0;
	m->floor_color = -1;
	m->ceiling_color = -1;
	m->player_orientation = 0;
	if (m->no_path)
		free(m->no_path);
	m->no_path = NULL;
	if (m->so_path)
		free(m->so_path);
	m->so_path = NULL;
	if (m->ea_path)
		free(m->ea_path);
	m->ea_path = NULL;
	if (m->we_path)
		free(m->we_path);
	m->we_path = NULL;
}

int	load_and_validate(t_map *m, char *path)
{
	int	fd;

	reset_map_data(m);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!load_map_content(m, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!validate_map(m))
		return (0);
	return (1);
}

t_map	*load_map(char *path)
{
	t_map	*m;

	m = init_map();
	if (!m)
		return (NULL);
	m->height = get_map_height(path, m);
	if (m->height == -1)
	{
		free_map(m);
		free(m);
		return (NULL);
	}
	if (!allocate_map(m))
	{
		free_map(m);
		free(m);
		return (NULL);
	}
	if (!load_and_validate(m, path))
	{
		free_map(m);
		free(m);
		return (NULL);
	}
	return (m);
}
