/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:25:28 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 16:24:21 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft2_strchr(char *s, int c);
char	*ft2_strjoin(char *left_str, char *buff);
size_t	ft2_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);

#endif
