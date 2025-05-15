/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:09:29 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Find the index of the first map line (starting with '1').
 */
int	find_map_start(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_strlen(file[i]) == 0 || ft_isspace(file[i][0]))
		{
			i++;
			continue ;
		}
		if (file[i][0] == 'F' || file[i][0] == 'C')
		{
			i++;
			continue ;
		}
		if (ft_strchr(file[i], '1'))
			return (i);
		i++;
	}
	return (-1);
}
