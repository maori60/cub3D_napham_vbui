#include "../includes/cub3d.h"

/**
 * Compte le nombre de lignes dans un fichier.
 */
static int count_file_lines(char *filepath) {
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return display_error(filepath, strerror(errno), FAILURE);
    int line_count = 0;
    char *line;
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
        if (!content[i - 1])
            return display_error(NULL, "Error: Memory allocation failed.", FAILURE);
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
    if (fd < 0)
        return display_error(filepath, strerror(errno), FAILURE);
    if (load_file_content(data->mapinfo.file, fd) == FAILURE) {
        close(fd);
        return FAILURE;
    }
    close(fd);
    return SUCCESS;
}
