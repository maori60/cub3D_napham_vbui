/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:30:48 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 19:30:52 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(t_map *m)
{
	int	i;

	i = 0;
	while (m->map && i < m->height)
		free(m->map[i++]);
	free(m->map);
	free(m->no_path);
	free(m->so_path);
	free(m->ea_path);
	free(m->we_path);
}
