/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:00:56 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:08:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Vérifie si un chemin correspond à un répertoire.
 */
static int is_directory(char *path) {
    int fd = open(path, O_DIRECTORY);
    if (fd >= 0) {
        close(fd);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si un fichier possède une extension spécifique.
 */
static int has_valid_extension(char *filename, const char *extension) {
    size_t len = ft_strlen(filename);
    size_t ext_len = ft_strlen(extension);
    return (len > ext_len && strcmp(filename + len - ext_len, extension) == 0);
}

/**
 * Valide un fichier donné en fonction de son rôle (carte ou texture).
 */
int validate_file_path(char *filename, int is_map_file) {
    if (is_directory(filename))
        return display_error(filename, "Error: File is a directory.", FAILURE);
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return display_error(filename, strerror(errno), FAILURE);
    close(fd);
    if (is_map_file && !has_valid_extension(filename, ".cub"))
        return display_error(filename, "Error: Invalid .cub file extension.", FAILURE);
    if (!is_map_file && !has_valid_extension(filename, ".xpm"))
        return display_error(filename, "Error: Invalid .xpm file extension.", FAILURE);
    return SUCCESS;
}
