/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 03:15:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:25:36 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	*rgb_allocation(char **split)
{
	int	*rgb;

	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		free_split(split);
		display_error_message(NULL, ERR_MALLOC, FAILURE);
		return (NULL);
	}
	return (rgb);
}

static int	validate_and_convert_rgb(char **split, int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!split[i] || !ft_isdigit(split[i][0]))
			return (FAILURE);
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	*parse_rgb_values(char *line)
{
	char	**split;
	int		*rgb;
	int		count;

	split = ft_split(line, ',');
	if (!split)
		return (display_error_message(NULL, ERR_FLOOR_CEILING, FAILURE), NULL);
	count = 0;
	while (split[count])
		count++;
	if (count != 3)
	{
		free_split(split);
		return (display_error_message(NULL, ERR_FLOOR_CEILING, FAILURE), NULL);
	}
	rgb = rgb_allocation(split);
	if (!rgb || validate_and_convert_rgb(split, rgb) == FAILURE)
	{
		free(rgb);
		free_split(split);
		return (display_error_message(NULL, ERR_TEX_RGB_VAL, FAILURE), NULL);
	}
	free_split(split);
	return (rgb);
}
