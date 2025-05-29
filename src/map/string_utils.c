/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:31:22 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 19:31:31 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*d;
	int		i;

	if (!s)
		return (NULL);
	d = malloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	ft_atoi(char *s)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + s[i] - '0';
		i++;
	}
	return (r);
}

char	*alloc_line(int size)
{
	char	*line;
	int		i;

	line = malloc(size);
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
		line[i++] = '\0';
	return (line);
}

char	*add_char(char *line, char c, int pos)
{
	char	*new;
	int		i;

	new = malloc(pos + 2);
	if (!new)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < pos)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(line);
	return (new);
}
