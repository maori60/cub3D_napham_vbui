/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:08 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:21:09 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	validate_map_walls(char **map, int height)
{
	int	i;
	int	j;

	if (!map || height <= 0)
		return (display_error_message(NULL,
				"Error: Invalid map structure.", FAILURE));
	printf("=== DEBUG : Checking map walls ===\n");
	print_debug_map(map, height);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (check_wall(map, i, j, height) == FAILURE)
				return (FAILURE);
			j++;
		}
		i++;
	}
	printf("[DEBUG] The map is properly surrounded by walls.\n");
	return (SUCCESS);
}

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
				printf("[DEBUG] Invalid character found at ");
				printf("(row: %d, col: %d) => '%c'\n", i, j, c);
				return (display_error_message(NULL,
						ERR_INV_LETTER, FAILURE));
			}
			j++;
		}
		i++;
	}
	printf("[DEBUG] All map characters are valid.\n");
	return (SUCCESS);
}

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
			if (is_space_adjacent(map, i, j))
			{
				printf("[DEBUG] Space found next to walkable tile ");
				printf("at (row: %d, col: %d)\n", i, j);
				return (display_error_message(NULL,
						"Error: Space is adjacent to a traversable area.",
						FAILURE));
			}
			j++;
		}
		i++;
	}
	printf("[DEBUG] No invalid adjacent space found.\n");
	return (SUCCESS);
}
