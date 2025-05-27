/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:04:23 by vbui              #+#    #+#             */
/*   Updated: 2025/05/27 23:05:05 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_number(char *str, int *index, int *value)
{
	*value = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		if (*value > 25 || (*value == 25 && str[*index] > '5'))
			return (-1);
		*value = *value * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (0);
}

static int	parse_rgb_component(char *str, int *index, int *component)
{
	if (parse_number(str, index, component) == -1)
		return (-1);
	if (*component > 255)
		return (-1);
	return (0);
}

int	parse_color(char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	if (parse_rgb_component(str, &i, &r) == -1)
		return (-1);
	if (str[i++] != ',')
		return (-1);
	if (parse_rgb_component(str, &i, &g) == -1)
		return (-1);
	if (str[i++] != ',')
		return (-1);
	if (parse_rgb_component(str, &i, &b) == -1)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}
