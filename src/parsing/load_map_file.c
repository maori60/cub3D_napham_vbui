/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 06:07:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/21 23:10:54 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/file_parser.h"

static int	open_and_store(char *filepath, t_game *data)
{
	int	fd;
	int	line_count;

	line_count = count_file_lines(filepath);
	if (line_count == FAILURE)
		return (FAILURE);
	data->mapinfo.file = malloc(sizeof(char *) * (line_count + 1));
	if (!data->mapinfo.file)
		return (display_error_message(NULL, ERR_MALLOC, FAILURE));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		free(data->mapinfo.file);
		return (display_error_message(filepath, strerror(errno), FAILURE));
	}
	if (load_file_content(data->mapinfo.file, fd) == FAILURE)
		return (close(fd), FAILURE);
	close(fd);
	return (SUCCESS);
}

int	load_map_file(char *filepath, t_game *data)
{
	int	map_start;

	if (open_and_store(filepath, data) == FAILURE)
		return (FAILURE);
	if (trim_file_lines(data->mapinfo.file) == FAILURE)
		return (FAILURE);
	if (parse_all_lines(data->mapinfo.file, data) == FAILURE)
		return (FAILURE);
	map_start = find_map_start(data->mapinfo.file);
	if (map_start == -1)
		return (display_error_message(NULL, ERR_INVALID_MAP, FAILURE));
	return (parse_and_validate_map(data, map_start));
}
