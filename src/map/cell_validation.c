/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:27:08 by napham            #+#    #+#             */
/*   Updated: 2025/05/31 00:24:49 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	validate_cell(t_map *m, int i, int j, int r_start)
{
	char	c;

	c = m->map[i][j];
	if (!is_map_char(c))
		return (err_msg(NULL, ERR_MAP_INVALID_CHAR), 0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (!set_player(m, c, i, j))
			return (err_msg(NULL, ERR_MAP_MULTIPLE_PLAYERS), 0);
	}
	if (!check_borders(m, i, j, r_start))
		return (err_msg(NULL, ERR_MAP_NOT_CLOSED), 0);
	if (c == ' ' && !check_space(m, i, j))
		return (err_msg(NULL, ERR_MAP_NOT_CLOSED), 0);
	return (1);
}

int	check_elements(t_map *m)
{
	if (m->element_count != 6)
	{
		err_msg(NULL, ERR_MAP_MISSING_ELEMENTS);
		return (0);
	}
	if (m->floor_color == -1 || m->ceiling_color == -1)
	{
		err_msg(NULL, ERR_MAP_MISSING_ELEMENTS);
		return (0);
	}
	if (!m->no_path || !m->so_path || !m->ea_path || !m->we_path)
	{
		err_msg(NULL, ERR_MAP_MISSING_ELEMENTS);
		return (0);
	}
	return (1);
}

int	validate_row(t_map *m, int i)
{
	int	j;
	int	r_start;

	j = 0;
	while (m->map[i][j] == ' ')
		j++;
	r_start = j;
	while (j < ft_strlen(m->map[i]))
	{
		if (!validate_cell(m, i, j, r_start))
			return (0);
		j++;
	}
	return (1);
}

int	validate_map(t_map *m)
{
	int	i;

	if (!check_elements(m))
		return (0);
	if (m->width < 3)
		return (err_msg(NULL, ERR_MAP_SMALL), 0);
	if (m->player_orientation == 0)
		return (err_msg(NULL, ERR_MAP_MISSING_PLAYER), 0);
	i = 0;
	while (i < m->height)
	{
		if (!validate_row(m, i))
			return (0);
		i++;
	}
	return (1);
}

t_map	*init_map(void)
{
	t_map	*m;

	m = malloc(sizeof(t_map));
	if (!m)
		return (NULL);
	ft_memset(m, 0, sizeof(t_map));
	m->floor_color = -1;
	m->ceiling_color = -1;
	return (m);
}
