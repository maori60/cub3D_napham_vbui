/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:10:35 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Initializes program data.
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
 * Frees MLX and texture resources before exiting.
 */
void	clean_exit(t_data *data, int exit_code)
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
 * Program entry point.
 */
int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc != 2)
		return (display_error_message(NULL, ERR_USAGE, FAILURE));
	if (load_map_file(argv[1], &data) == FAILURE)
		clean_exit(&data, FAILURE);
	if (validate_textures_and_colors(&data, &data.texinfo) == FAILURE)
		clean_exit(&data, FAILURE);
	init_mlx(&data);
	init_textures(&data);
	mlx_loop(data.mlx);
	clean_exit(&data, SUCCESS);
}
