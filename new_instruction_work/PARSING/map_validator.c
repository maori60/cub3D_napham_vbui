/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:08 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:10:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

/**
 * Affiche la carte pour le débogage.
 */
void	print_debug_map(char **map, int height)
{
	int	i;

	printf("=== DEBUG: Affichage de la carte ===\n");
	i = 0;
	while (i < height)
	{
		printf("Ligne %d: '%s'\n", i, map[i]);
		i++;
	}
	printf("==================================\n");
}

/**
 * Vérifie que la carte est entourée de murs.
 */
int	validate_map_walls(char **map, int height)
{
	int	i;
	int	j;

	if (!map || height <= 0)
		return (display_error_message(NULL, "Error: Invalid map structure.",
				FAILURE));
	printf("=== DEBUG : Vérification des murs ===\n");
	print_debug_map(map, height);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == height - 1 || j == 0 || map[i][j + 1] == '\0')
				&& map[i][j] != '1' && !ft_isspace(map[i][j]))
			{
				printf("[DEBUG] Mur absent à (ligne: %d, colonne: %d) => '%c'\n",
					i, j, map[i][j]);
				return (display_error_message(NULL, ERR_MAP_NO_WALLS, FAILURE));
			}
			j++;
		}
		i++;
	}
	printf("[DEBUG] La carte est bien entourée de murs.\n");
	return (SUCCESS);
}

/**
 * Valide les caractères présents dans la carte.
 */
int	validate_map_characters(char **map, int height, int width)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			c = map[i][j];
			if (!ft_strchr("01NSEW ", c))
			{
				printf("[DEBUG] Caractère invalide détecté à (ligne: %d, colonne: %d) => '%c'\n",
					i, j, c);
				return (display_error_message(NULL, ERR_INV_LETTER, FAILURE));
			}
			j++;
		}
		i++;
	}
	printf("[DEBUG] Tous les caractères de la carte sont valides.\n");
	return (SUCCESS);
}

/**
 * Vérifie que les espaces ne sont pas adjacents à des `0` ou à un caractère joueur.
 */
int	validate_map_spaces(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 1;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == ' ' && (ft_strchr("0NSEW", map[i - 1][j])
				|| ft_strchr("0NSEW", map[i + 1][j])
				|| ft_strchr("0NSEW", map[i][j - 1])
				|| ft_strchr("0NSEW", map[i][j + 1])))
			{
				printf("[DEBUG] Espace adjacent à une zone traversable à (ligne: %d, colonne: %d)\n",
					i, j);
				return (display_error_message(NULL,
						"Error: Space is adjacent to a traversable area.",
						FAILURE));
			}
			j++;
		}
		i++;
	}
	printf("[DEBUG] Aucun problème d'espace adjacent détecté.\n");
	return (SUCCESS);
}
