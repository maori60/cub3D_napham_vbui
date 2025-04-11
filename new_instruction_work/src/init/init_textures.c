/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:30:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:07:22 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_floor_ceiling_hex(t_texinfo *t)
{
	t->hex_floor = rgb_to_hex(t->floor[0], t->floor[1], t->floor[2]);
	t->hex_ceiling = rgb_to_hex(t->ceiling[0], t->ceiling[1], t->ceiling[2]);
}

void	configure_floor_ceiling_colors(t_texinfo *textures)
{
	if (!textures->floor
		|| !textures->ceiling)
	{
		printf("[ERROR] Couleurs sol ou plafond manquantes\n");
		return ;
	}
	set_floor_ceiling_hex(textures);
	printf("[DEBUG] Sol : 0x%06X\n", textures->hex_floor);
	printf("[DEBUG] Plafond : 0x%06X\n", textures->hex_ceiling);
}

static void	copy_texture_data(t_img *tmp, int *buf, t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->texinfo.height)
	{
		x = 0;
		while (x < d->texinfo.width)
		{
			buf[y * d->texinfo.width + x]
				= tmp->addr[y * d->texinfo.width + x];
			x++;
		}
		y++;
	}
}

static int	*xpm_to_img(t_data *d, char *path)
{
	t_img	tmp;
	int		*buffer;

	init_texture_img(d, &tmp, path);
	if (!tmp.addr)
	{
		printf("[ERROR] Texture invalide : %s\n", path);
		mlx_destroy_image(d->mlx, tmp.img);
		return (NULL);
	}
	buffer = ft_calloc(1,
			sizeof(int) * d->texinfo.width * d->texinfo.height);
	if (!buffer)
		clean_exit(d, err_msg(NULL, ERR_MALLOC, 1));
	copy_texture_data(&tmp, buffer, d);
	mlx_destroy_image(d->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *d)
{
	d->textures = ft_calloc(4, sizeof(int *));
	if (!d->textures)
		clean_exit(d, err_msg(NULL, ERR_MALLOC, 1));
	d->textures[NORTH] = xpm_to_img(d, d->texinfo.north);
	if (!d->textures[NORTH])
		clean_exit(d, err_msg("mlx", "Erreur texture NORTH", 1));
	d->textures[SOUTH] = xpm_to_img(d, d->texinfo.south);
	if (!d->textures[SOUTH])
		clean_exit(d, err_msg("mlx", "Erreur texture SOUTH", 1));
	d->textures[EAST] = xpm_to_img(d, d->texinfo.east);
	if (!d->textures[EAST])
		clean_exit(d, err_msg("mlx", "Erreur texture EAST", 1));
	d->textures[WEST] = xpm_to_img(d, d->texinfo.west);
	if (!d->textures[WEST])
		clean_exit(d, err_msg("mlx", "Erreur texture WEST", 1));
	configure_floor_ceiling_colors(&d->texinfo);
}
