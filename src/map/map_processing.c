/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:30:30 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 19:30:35 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	store_map_line(t_map *m, char *line, int i)
{
	m->map[i] = ft_strdup(line);
	if (!m->map[i])
		return (0);
	if (ft_strlen(m->map[i]) > m->width)
		m->width = ft_strlen(m->map[i]);
	return (1);
}

int	process_map_line(t_map *m, char *line, int *i)
{
	int	res;

	res = parse_elem(m, line);
	if (res == -1)
		return (0);
	if (res == 1)
		return (1);
	if (ft_strlen(line) > 0 && is_map_line(line))
	{
		if (!store_map_line(m, line, *i))
			return (0);
		(*i)++;
	}
	return (1);
}

int	load_map_content(t_map *m, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = read_line(fd);
	while (line)
	{
		if (!process_map_line(m, line, &i))
		{
			free(line);
			return (0);
		}
		free(line);
		line = read_line(fd);
	}
	return (1);
}

int	check_first_last_row(char c)
{
	return (c == '1' || c == ' ');
}

int	check_row_overflow(t_map *m, int i, int j)
{
	if (i > 0 && j >= ft_strlen(m->map[i - 1]))
		return (m->map[i][j] == '1');
	if (i < m->height - 1 && j >= ft_strlen(m->map[i + 1]))
		return (m->map[i][j] == '1');
	return (1);
}
