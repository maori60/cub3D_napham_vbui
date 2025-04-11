/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:45:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:25:03 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_rgb_colors(t_texinfo *textures, char *line, int is_floor)
{
	int	*rgb;

	rgb = parse_rgb_values(line);
	if (!rgb)
		return (FAILURE);
	if (is_floor)
	{
		textures->floor = rgb;
		textures->floor_color = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	}
	else
	{
		textures->ceiling = rgb;
		textures->ceiling_color = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	}
	free(rgb);
	return (SUCCESS);
}

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
