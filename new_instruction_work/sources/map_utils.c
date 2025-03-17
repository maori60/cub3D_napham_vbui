/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:17:23 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/**
 * Trouve l'index de la première ligne contenant la map (qui commence par '1').
 */
int	find_map_start(char **file)
{
	int	i;
	i = 0;

	while (file[i])
	{
		// Debugging pour voir quelles lignes sont analysées
		printf("[DEBUG] find_map_start: Ligne %d: '%s'\n", i, file[i]);

		// Ignore les lignes vides ou contenant uniquement des espaces
		if (ft_strlen(file[i]) == 0 || ft_isspace(file[i][0]))
		{
			i++;
			continue ;
		}

		// Ignore les lignes contenant 'F' ou 'C' au début (couleurs sol/plafond)
		if (file[i][0] == 'F' || file[i][0] == 'C')
		{
			i++;
			continue ;
		}

		// Si une ligne commence par '1', elle est considérée comme le début de la carte
		if (ft_strchr(file[i], '1'))
			return (i);

		i++;
	}
	
	return (-1); // Retourne -1 si aucune ligne de carte valide n'est trouvée.
}
