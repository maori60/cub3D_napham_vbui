/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/03/17 16:44:21 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Initialise les données du programme.
 */
void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->mapinfo.file = NULL;
	data->mapinfo.map = NULL;
	data->mapinfo.width = 0;
	data->mapinfo.height = 0;

	data->texinfo.north = NULL;
	data->texinfo.south = NULL;
	data->texinfo.west = NULL;
	data->texinfo.east = NULL;
	data->texinfo.floor = NULL;
	data->texinfo.ceiling = NULL;
	data->texinfo.hex_floor = 0;
	data->texinfo.hex_ceiling = 0;
}

/**
 * Libère les ressources MLX et les textures avant de quitter proprement.
 */
void clean_exit(t_data *data, int exit_code)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_data(data);
	exit(exit_code);
}

/**
 * Fonction principale du programme.
 */
int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);

	// Vérification du nombre d'arguments
	if (argc != 2)
		return (display_error_message(NULL, ERR_USAGE, FAILURE));

	// Chargement et validation du fichier .cub
	if (load_map_file(argv[1], &data) == FAILURE)
		clean_exit(&data, FAILURE);

	if (validate_textures_and_colors(&data, &data.texinfo) == FAILURE)
		clean_exit(&data, FAILURE);

	// Initialisation de MLX (fenêtre + affichage)
	init_mlx(&data);

	// Chargement des textures et configuration des couleurs
	init_textures(&data);

	// Boucle principale MLX
	mlx_loop(data.mlx);

	// Libération des ressources avant de quitter
	clean_exit(&data, SUCCESS);
}
