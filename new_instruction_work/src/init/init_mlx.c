/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:00 by vbui              #+#    #+#             */
/*   Updated: 2025/03/17 16:24:58 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/cub3d.h"


// /**
//  * Initialise une image MLX avec les dimensions spécifiées.
//  */
// void	init_img(t_data *data, t_img *image, int width, int height)
// {
// 	image->img = mlx_new_image(data->mlx, width, height);
// 	if (!image->img)
// 		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
// 	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
// 			&image->size_line, &image->endian);
// }

// /**
//  * Charge une image XPM en mémoire et la stocke dans une structure `t_img`.
//  */
// void	init_texture_img(t_data *data, t_img *image, char *path)
// {
// 	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.width,
// 			&data->texinfo.height);
// 	if (!image->img)
// 	{
// 		printf("Erreur: Impossible de charger la texture %s\n", path);
// 		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
// 	}
// 	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
// 			&image->size_line, &image->endian);
// }

// /**
//  * Initialise MiniLibX, crée une fenêtre et configure les paramètres de base.
//  */
// void	init_mlx(t_data *data)
// {
// 	data->mlx = mlx_init();
// 	if (!data->mlx)
// 		clean_exit(data, err_msg("mlx", ERR_MLX_START, 1));

// 	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
// 	if (!data->win)
// 		clean_exit(data, err_msg("mlx", ERR_MLX_WIN, 1));

// 	// // Déplace la souris au centre de l'écran (uniquement si bonus activé)
// 	// if (BONUS) 
// 	// 	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
// }


#include "../includes/cub3d.h"

/**
 * Vérifie si MLX est bien initialisé avant d'aller plus loin.
 */
void	init_mlx(t_data *data)
{
	printf("[DEBUG] Initialisation de MLX...\n");
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, err_msg("mlx", ERR_MLX_START, 1));
	printf("[DEBUG] MLX initialisé avec succès.\n");

	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		clean_exit(data, err_msg("mlx", ERR_MLX_WIN, 1));
	printf("[DEBUG] Fenêtre MLX créée avec succès.\n");
}

/**
 * Initialise une image MLX avec vérification.
 */
void	init_img(t_data *data, t_img *image, int width, int height)
{
	printf("[DEBUG] Création d'une image MLX de %dx%d...\n", width, height);
	image->img = mlx_new_image(data->mlx, width, height);
	if (!image->img)
	{
		printf("[ERROR] Échec de création de l'image MLX.\n");
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	}
	printf("[DEBUG] Image MLX créée avec succès.\n");

	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

/**
 * Charge une texture XPM et vérifie qu'elle est valide.
 */
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	printf("[DEBUG] Tentative de chargement de la texture : %s\n", path);

	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.width,
			&data->texinfo.height);
	if (!image->img)
	{
		printf("[ERROR] Impossible de charger la texture : %s\n", path);
		clean_exit(data, err_msg("mlx", ERR_MLX_IMG, 1));
	}
	printf("[DEBUG] Texture chargée avec succès : %s\n", path);

	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}
