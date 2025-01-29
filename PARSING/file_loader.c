/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:48 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:41:17 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int find_map_start(char **file) {
    int i = 0;
    while (file[i]) {
        if (ft_strchr(file[i], '1'))
            return i;
        i++;
    }
    return -1;
}
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
        free(data->mapinfo.file);
        return FAILURE;
    }

    close(fd);

    for (int i = 0; data->mapinfo.file[i]; i++) {
        if (parse_texture_line(data->mapinfo.file[i], data) == FAILURE) {
            free_data(data);
            return FAILURE;
        }
    }

    // Valider la map avec les nouvelles fonctions
    int map_start = find_map_start(data->mapinfo.file);
    if (map_start == -1)
        return display_error(NULL, "Error: No map found in file.", FAILURE);

    if (load_map_data(data->mapinfo.file, data, map_start) == FAILURE)
        return FAILURE;

    if (validate_map_borders(data->mapinfo.map, data->mapinfo.height) == FAILURE)
        return FAILURE;
    
    if (validate_map_characters(data->mapinfo.map, data->mapinfo.height, data->mapinfo.width) == FAILURE)
        return FAILURE;

    if (validate_map_spaces(data->mapinfo.map, data->mapinfo.height, data->mapinfo.width) == FAILURE)
        return FAILURE;

    if (validate_floor_and_ceiling(&data->texinfo) == FAILURE)
        return FAILURE;

    return SUCCESS;
}

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

int load_file_content(char **content, int fd) {
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
