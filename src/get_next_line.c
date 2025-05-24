/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:18:47 by napham            #+#    #+#             */
/*   Updated: 2025/05/24 10:19:35 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
read_from_buffer(int fd, char *buffer, int *buffer_pos, int *buffer_len)
*/
static int	read_from_buffer(int fd, char *b, int *bp, int *bl)
{
	if (*bp >= *bl)
	{
		*bl = read(fd, b, 1024);
		*bp = 0;
		if (*bl <= 0)
			return (0);
	}
	return (1);
}

static char	*process_line(char *line, int line_len, int buffer_len)
{
	if (line_len == 0 && buffer_len <= 0)
	{
		free(line);
		return (NULL);
	}
	line[line_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	buffer_pos = 0;
	static int	buffer_len = 0;
	char		*line;
	int			line_len;

	line = malloc(4096);
	if (!line)
		return (NULL);
	line_len = 0;
	while (1)
	{
		if (!read_from_buffer(fd, buffer, &buffer_pos, &buffer_len))
			break ;
		if (buffer[buffer_pos] == '\n')
		{
			buffer_pos++;
			break ;
		}
		line[line_len++] = buffer[buffer_pos++];
	}
	return (process_line(line, line_len, buffer_len));
}
