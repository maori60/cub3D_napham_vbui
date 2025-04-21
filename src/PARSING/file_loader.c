/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:48 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:47:02 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_file_lines(char *filepath)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (display_error_message(filepath, strerror(errno), FAILURE));
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

int	load_file_content(char **content, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		content[i++] = ft_strdup(line);
		if (!content[i - 1])
		{
			while (i-- > 0)
				free(content[i]);
			free(content);
			free(line);
			return (display_error_message(NULL, ERR_MALLOC, FAILURE));
		}
		free(line);
		line = get_next_line(fd);
	}
	content[i] = NULL;
	return (SUCCESS);
}
