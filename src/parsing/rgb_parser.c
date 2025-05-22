/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:45:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/22 20:36:57 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_floor_and_ceiling(t_texinfo *texinfo)
{
	if (!texinfo)
		return (display_error_message(NULL,
				"Error: Texture info is NULL.", FAILURE));
	if (texinfo->floor_color == -1 || texinfo->ceiling_color == -1)
		return (display_error_message(NULL,
				"Error: Floor or ceiling color missing.", FAILURE));
	printf("[DEBUG] Floor and ceiling colors are valid.\n");
	return (SUCCESS);
}
