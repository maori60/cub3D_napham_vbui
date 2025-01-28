/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:25:04 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:23:18 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>

char *ft_read_to_left_str(int fd, char *left_str) {
    char *buff;
    int rd_bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);

    rd_bytes = 1;
    while (!ft2_strchr(left_str, '\n') && rd_bytes > 0) {
        rd_bytes = read(fd, buff, BUFFER_SIZE);
        if (rd_bytes == -1) {
            free(buff);
            free(left_str);
            return (NULL);
        }
        buff[rd_bytes] = '\0';
        left_str = ft2_strjoin(left_str, buff);
        if (!left_str) {
            free(buff);
            return (NULL);
        }
    }
    free(buff);
    return (left_str);
}

char *get_next_line(int fd) {
    char *line;
    static char *left_str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    left_str = ft_read_to_left_str(fd, left_str);
    if (!left_str)
        return (NULL);

    line = ft_get_line(left_str);
    left_str = ft_new_left_str(left_str);

    return (line);
}
