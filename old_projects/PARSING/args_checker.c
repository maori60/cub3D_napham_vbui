/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:00:56 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:05:05 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Vérifie si le fichier est un répertoire.
 */
static int	is_directory(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
		return (1);
	return (0);
}

/**
 * Vérifie l'extension du fichier.
 */
static int	has_valid_extension(char *filename, const char *extension)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (len <= ext_len)
		return (0);
	return (ft_strncmp(filename + len - ext_len, extension, ext_len) == 0);
}

/**
 * Vérifie que le fichier existe, qu'il est lisible et a la bonne extension.
 */
int	validate_file_path(char *filename, int is_map_file)
{
	int		fd;
	char	buffer[1];

	if (is_directory(filename))
		return (display_error_message(filename, ERR_FILE_IS_DIR, FAILURE));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (display_error_message(filename, strerror(errno), FAILURE));
	if (read(fd, buffer, 1) <= 0)
	{
		close(fd);
		return (display_error_message(filename, "Error: Empty file.", FAILURE));
	}
	close(fd);
	if (is_map_file && !has_valid_extension(filename, ".cub"))
		return (display_error_message(filename, ERR_FILE_NOT_CUB, FAILURE));
	if (!is_map_file && !has_valid_extension(filename, ".xpm"))
		return (display_error_message(filename, ERR_FILE_NOT_XPM, FAILURE));
	return (SUCCESS);
}
