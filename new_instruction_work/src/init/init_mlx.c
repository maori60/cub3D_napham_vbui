/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:08:03 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Initialize the MLX connection and create a window.
 */
void	init_mlx(t_data *data)
{
	printf("[DEBUG] Initializing MLX...\n");
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, err_msg("mlx", ERR_MLX_START, 1));
	printf("[DEBUG] MLX initialized successfully.\n");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		clean_exit(data, err_msg("mlx", ERR_MLX_WIN, 1));
	printf("[DEBUG] MLX window created successfully.\n");
}

/**
 * Create an MLX image and retrieve its pixel information.
 */
void	init_img(t_data *data, t_img *image, int width, int height)
{
	printf("[DEBUG] Creating an MLX image of %dx%d...\n", width, height);
	image->img = mlx_new_image(data->mlx, width, height);
	if (!image->img)
	{
		printf("[ERROR] Failed to create MLX image.\n");
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	}
	printf("[DEBUG] MLX image created successfully.\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

/**
 * Load an XPM texture from the given path.
 */
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	printf("[DEBUG] Attempting to load texture: %s\n", path);
	image->img = mlx_xpm_file_to_image(data->mlx, path,
			&data->texinfo.width, &data->texinfo.height);
	if (!image->img)
	{
		printf("[ERROR] Failed to load texture: %s\n", path);
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	}
	printf("[DEBUG] Texture loaded successfully: %s\n", path);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}
