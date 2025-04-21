/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:25:59 by vbui              #+#    #+#             */
/*   Updated: 2025/04/10 02:20:09 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

size_t	ft2_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft2_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft2_strjoin(char *left_str, char *buff)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = ft2_strlen(left_str);
	len2 = ft2_strlen(buff);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, left_str, len1);
	ft_memcpy(new_str + len1, buff, len2);
	new_str[len1 + len2] = '\0';
	free(left_str);
	return (new_str);
}

char	*ft_get_line(char *left_str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!left_str || !left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, left_str, i);
	line[i] = '\0';
	return (line);
}

char	*ft_new_left_str(char *left_str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	new_str = malloc(ft2_strlen(left_str + i + 1) + 1);
	if (!new_str)
		return (NULL);
	i++;
	while (left_str[i])
		new_str[j++] = left_str[i++];
	new_str[j] = '\0';
	free(left_str);
	return (new_str);
}
