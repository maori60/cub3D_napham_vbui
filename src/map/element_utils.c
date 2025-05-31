/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:29:13 by napham            #+#    #+#             */
/*   Updated: 2025/05/31 00:15:40 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	parse_elem(t_map *m, char *line)
{
	int	i;
	int	res;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	res = set_texture(m, line, i);
	if (res == 1)
		;
	else if (line[i] == 'F' && line[i + 1] == ' ')
		m->floor_color = parse_rgb(line + i + 2);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		m->ceiling_color = parse_rgb(line + i + 2);
	else
		return (0);
	m->element_count++;
	return (1);
}

int	is_map_char(char c)
{
	if (c == ' ' || c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int	count_map_lines(int fd, t_map *m)
{
	char	*line;
	int		count;
	int		map_started;

	count = 0;
	line = read_line(fd);
	map_started = 0;
	while (line)
	{
		if (!map_started)
		{
			if (parse_elem(m, line) == 0 && m->element_count == 6
				&& !is_empty_line(line))
				map_started = 1;
		}
		if (map_started)
			count++;
		free(line);
		line = read_line(fd);
	}
	return (count);
}
