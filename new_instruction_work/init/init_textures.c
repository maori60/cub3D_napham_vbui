/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:30:00 by vbui              #+#    #+#             */
/*   Updated: 2025/03/17 17:02:47 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// /**
//  * Convertit un tableau de trois valeurs RGB en une valeur hexadécimale.
//  */
// unsigned int	rgb_to_hex(int r, int g, int b)
// {
// 	return ((r << 16) | (g << 8) | b);
// }

/**
 * Configure les couleurs du sol et du plafond à partir des valeurs RGB lues lors du parsing.
 */
void	configure_floor_ceiling_colors(t_texinfo *textures)
{
	if (!textures->floor || !textures->ceiling)
	{
		printf("[ERROR] Les couleurs du sol ou du plafond sont manquantes !\n");
		return;
	}

	textures->hex_floor = rgb_to_hex(textures->floor[0], textures->floor[1], textures->floor[2]);
	textures->hex_ceiling = rgb_to_hex(textures->ceiling[0], textures->ceiling[1], textures->ceiling[2]);

	printf("[DEBUG] Couleur du sol en hex : 0x%06X\n", textures->hex_floor);
	printf("[DEBUG] Couleur du plafond en hex : 0x%06X\n", textures->hex_ceiling);
}

/**
 * Convertit une image XPM en un buffer d'images et retourne un tableau d'entiers.
 */
static int *xpm_to_img(t_data *data, char *path) 
{
    t_img tmp; 
    int *buffer;
    int x, y;

    printf("[DEBUG] Chargement XPM : %s\n", path);
    init_texture_img(data, &tmp, path);

    if (!tmp.addr)
    {
        printf("[ERROR] Données de texture non valides pour %s\n", path);
        mlx_destroy_image(data->mlx, tmp.img);
        return NULL;
    }

    buffer = ft_calloc(1, sizeof(int) * data->texinfo.width * data->texinfo.height);
    if (!buffer)
    {
        printf("[ERROR] Allocation du buffer de texture échouée.\n");
        clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
    }

    y = 0;
    while (y < data->texinfo.height)
    {
        x = 0;
        while (x < data->texinfo.width)
        {
            buffer[y * data->texinfo.width + x] = tmp.addr[y * data->texinfo.width + x];
            x++;
        }
        y++;
    }

    mlx_destroy_image(data->mlx, tmp.img);
    printf("[DEBUG] XPM chargé avec succès : %s\n", path);

    return buffer;
}

/**
 * Initialise et charge toutes les textures ainsi que les couleurs du sol et du plafond.
 */
void init_textures(t_data *data) 
{
    data->textures = ft_calloc(4, sizeof(int *)); 
    if (!data->textures) 
        clean_exit(data, err_msg(NULL, ERR_MALLOC, 1)); 

    data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
    if (!data->textures[NORTH])
        clean_exit(data, err_msg("mlx", "Erreur chargement texture NORTH", 1));

    data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
    if (!data->textures[SOUTH])
        clean_exit(data, err_msg("mlx", "Erreur chargement texture SOUTH", 1));

    data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
    if (!data->textures[EAST])
        clean_exit(data, err_msg("mlx", "Erreur chargement texture EAST", 1));

    data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
    if (!data->textures[WEST])
        clean_exit(data, err_msg("mlx", "Erreur chargement texture WEST", 1));

    // Configuration des couleurs du sol et du plafond après chargement des textures
    configure_floor_ceiling_colors(&data->texinfo);
}

/**
 * Initialise la structure `t_texinfo` avec des valeurs par défaut.
 */
void init_texinfo(t_texinfo *textures) 
{
	textures->north = NULL; 
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
}
