/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/01/30 00:13:50 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
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

	data->texinfo.floor_color = -1;
	data->texinfo.ceiling_color = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);

	if (argc != 2)
		return (display_error_message(NULL, ERR_USAGE, FAILURE));

	if (load_map_file(argv[1], &data) == FAILURE)
	{
		free_data(&data);
		return (FAILURE);
	}

	if (validate_textures_and_colors(&data, &data.texinfo) == FAILURE)
	{
		free_data(&data);
		return (FAILURE);
	}

	printf("✅ Parsing réussi !\n");
	free_data(&data);
	return (SUCCESS);
}
