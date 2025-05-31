/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:29:39 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 20:43:59 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		r;

	line = alloc_line(1);
	if (!line)
		return (NULL);
	i = 0;
	r = read(fd, &c, 1);
	while (r > 0 && c != '\n')
	{
		line = add_char(line, c, i++);
		if (!line)
			return (NULL);
		r = read(fd, &c, 1);
	}
	if (r <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	get_color_val(char *s, int *i)
{
	int	val;

	val = ft_atoi(s + *i);
	while (s[*i] >= '0' && s[*i] <= '9')
		(*i)++;
	return (val);
}

int	parse_rgb(char *s)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	r = get_color_val(s, &i);
	if (s[i++] != ',')
		return (-1);
	g = get_color_val(s, &i);
	if (s[i++] != ',')
		return (-1);
	b = get_color_val(s, &i);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

char	*trim_path(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] == ' ')
		i++;
	j = ft_strlen(s) - 1;
	while (j >= i && s[j] == ' ')
		j--;
	s[j + 1] = '\0';
	return (ft_strdup(s + i));
}

int	set_texture(t_map *m, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		m->no_path = trim_path(line + i + 3);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		m->so_path = trim_path(line + i + 3);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		m->ea_path = trim_path(line + i + 3);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		m->we_path = trim_path(line + i + 3);
	else
		return (0);
	return (1);
}
