/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:59:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:19:37 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

void	print_debug_map(char **map, int height)
{
	int	i;

	printf("=== DEBUG: Printing map ===\n");
	i = 0;
	while (i < height)
	{
		printf("Line %d: '%s'\n", i, map[i]);
		i++;
	}
	printf("==================================\n");
}

int	is_space_adjacent(char **map, int i, int j)
{
	if (map[i][j] == ' '
		&& (ft_strchr("0NSEW", map[i - 1][j])
			|| ft_strchr("0NSEW", map[i + 1][j])
			|| ft_strchr("0NSEW", map[i][j - 1])
			|| ft_strchr("0NSEW", map[i][j + 1])))
		return (1);
	return (0);
}

int	check_wall(char **map, int i, int j, int height)
{
	if ((i == 0 || i == height - 1 || j == 0 || map[i][j + 1] == '\0')
		&& map[i][j] != '1' && !ft_isspace(map[i][j]))
	{
		printf("[DEBUG] Missing wall at (row: %d, col: %d) => '%c'\n",
			i, j, map[i][j]);
		return (display_error_message(NULL, ERR_MAP_NO_WALLS, FAILURE));
	}
	return (SUCCESS);
}
