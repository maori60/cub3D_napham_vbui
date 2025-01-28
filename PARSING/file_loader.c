/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:48 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:28:12 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

/**
 * Compte le nombre de lignes dans un fichier.
 */
int count_file_lines(char *filepath) {
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return display_error(filepath, strerror(errno), FAILURE);

    int line_count = 0;
    char *line = NULL;

    while ((line = get_next_line(fd))) {
        line_count++;
        free(line);
    }

    close(fd);
    return line_count;
}

/**
 * Charge le contenu d'un fichier dans un tableau.
 */
static int load_file_content(char **content, int fd) {
    int i = 0;
    char *line;

    while ((line = get_next_line(fd))) {
        content[i++] = ft_strdup(line);
        if (!content[i - 1]) {
            for (int j = 0; j < i - 1; j++)
                free(content[j]);
            free(content);
            free(line);
            return display_error(NULL, "Error: Memory allocation failed.", FAILURE);
        }
        free(line);
    }
    content[i] = NULL;
    return SUCCESS;
}

/**
 * Lit un fichier et charge ses lignes dans la structure.
 */
int load_map_file(char *filepath, t_data *data) {
    int line_count = count_file_lines(filepath);
    if (line_count == FAILURE)
        return FAILURE;

    data->mapinfo.file = malloc(sizeof(char *) * (line_count + 1));
    if (!data->mapinfo.file)
        return display_error(NULL, "Error: Memory allocation failed.", FAILURE);

    int fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        free(data->mapinfo.file);
        return display_error(filepath, strerror(errno), FAILURE);
    }

    if (load_file_content(data->mapinfo.file, fd) == FAILURE) {
        close(fd);
        for (int i = 0; i < line_count; i++)
            free(data->mapinfo.file[i]);
        free(data->mapinfo.file);
        return FAILURE;
    }

    close(fd);
    return SUCCESS;
}
