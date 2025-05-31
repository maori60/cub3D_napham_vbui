/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:06:40 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 20:59:37 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_borders(t_map *m, int i, int j, int r_start)
{
	if (i == 0 || i == m->height - 1)
		return (check_first_last_row(m->map[i][j]));
	if (j == r_start || j == ft_strlen(m->map[i]) - 1)
		return (m->map[i][j] == '1');
	return (check_row_overflow(m, i, j));
}

int	get_adj_char(t_map *m, int ni, int nj)
{
	if (ni < 0 || ni >= m->height || nj < 0)
		return (-1);
	if (nj >= ft_strlen(m->map[ni]))
		return (-1);
	return (m->map[ni][nj]);
}

int	check_adjacent(t_map *m, int i, int j, int di_dj)
{
	int	ni;
	int	nj;
	int	adj_char;

	ni = i;
	nj = j;
	if (di_dj == 0)
		ni = i - 1;
	else if (di_dj == 1)
		ni = i + 1;
	else if (di_dj == 2)
		nj = j - 1;
	else if (di_dj == 3)
		nj = j + 1;
	adj_char = get_adj_char(m, ni, nj);
	if (adj_char == -1 || adj_char == '1' || adj_char == ' ')
		return (1);
	return (0);
}

int	check_space(t_map *m, int i, int j)
{
	if (!check_adjacent(m, i, j, 0))
		return (0);
	if (!check_adjacent(m, i, j, 1))
		return (0);
	if (!check_adjacent(m, i, j, 2))
		return (0);
	if (!check_adjacent(m, i, j, 3))
		return (0);
	return (1);
}

int	set_player(t_map *m, char c, int i, int j)
{
	if (m->player_orientation)
		return (0);
	m->player_orientation = c;
	m->player_x = j;
	m->player_y = i;
	return (1);
}
