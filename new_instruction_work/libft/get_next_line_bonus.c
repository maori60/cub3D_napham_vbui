/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:27:13 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 16:21:02 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../libft/libft.h"
#include <unistd.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	if (read(fd, NULL, 0) == -1)
		return (free(left_str), NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free (left_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || !BUFFER_SIZE)
		return (0);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
/*#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line1;
	char	*line2;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("toto.txt", O_RDONLY);
	fd2 = open("toto2.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		line1 = get_next_line(fd1);
		printf("line [%02d]: %s", i, line1);
		line2 = get_next_line(42);
		printf("line [%02d]: %s", i, line2);
		if (line1 == NULL && line2 == NULL)
			break ;
		close(fd1);
		free(line1);
		free(line2);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}*/