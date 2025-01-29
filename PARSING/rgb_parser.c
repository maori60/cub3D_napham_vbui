/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:13:48 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:12:43 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Libère un tableau de strings.
 */
static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

/**
 * Convertit une ligne RGB (ex: "255,0,100") en tableau d'entiers.
 */
static int	*parse_rgb_values(char *line)
{
	char	**split;
	int		*rgb;
	int		i;

	split = ft_split(line, ',');
	if (!split)
		return (display_error_message(NULL, ERR_FLOOR_CEILING, FAILURE), NULL);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		free_split(split);
		return (display_error_message(NULL, ERR_MALLOC, FAILURE), NULL);
	}
	i = 0;
	while (i < 3)
	{
		if (!split[i] || !ft_isdigit(split[i][0]))
		{
			free(rgb);
			free_split(split);
			return (display_error_message(NULL, ERR_FLOOR_CEILING, FAILURE), NULL);
		}
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free(rgb);
			free_split(split);
			return (display_error_message(NULL, ERR_TEX_RGB_VAL, FAILURE), NULL);
		}
		i++;
	}
	free_split(split);
	return (rgb);
}

/**
 * Parse une ligne de couleur RGB (F ou C).
 */
int	parse_rgb_colors(t_texinfo *textures, char *line, int is_floor)
{
	int	*rgb;

	rgb = parse_rgb_values(line);
	if (!rgb)
		return (FAILURE);
	if (is_floor)
	{
		textures->floor = rgb;
		textures->floor_color = rgb_to_hex(rgb); // 🔥 Correction ici
	}
	else
	{
		textures->ceiling = rgb;
		textures->ceiling_color = rgb_to_hex(rgb); // 🔥 Correction ici
	}
	return (SUCCESS);
}

#include "../includes/cub3d.h"

/**
 * Vérifie que les couleurs du sol et du plafond ont bien été définies.
 */
int	validate_floor_and_ceiling(t_texinfo *texinfo)
{
	if (!texinfo)
		return (display_error_message(NULL, "Error: Texture info is NULL.", FAILURE));
	if (texinfo->floor_color == -1 || texinfo->ceiling_color == -1)
		return (display_error_message(NULL, "Error: Floor or ceiling color missing.", FAILURE));
	printf("[DEBUG] Les couleurs du sol et du plafond sont valides.\n");
	return (SUCCESS);
}
