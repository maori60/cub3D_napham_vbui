/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:38:29 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:38:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trim_texture_path(char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		display_error_message(NULL, ERR_MALLOC, FAILURE);
	return (trimmed);
}

int	store_texture(char **texture, char *path)
{
	if (*texture != NULL)
	{
		free(path);
		return (display_error_message(NULL,
				"Error: Duplicate texture definition.",
				FAILURE));
	}
	*texture = path;
	return (SUCCESS);
}
