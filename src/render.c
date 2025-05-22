/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:16:53 by napham            #+#    #+#             */
/*   Updated: 2025/05/22 22:48:51 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_image(t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel_color(t_img *img, int x, int y);

int	render_frame(t_game *game)
{
	clear_image(game->img);
	move_player(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	render_wall(t_game *game, t_ray *ray, int x)
{
	int		y;
	t_img	*texture;
	int		tex_y;
	int		color;

	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			texture = game->textures.east;
		else
			texture = game->textures.west;
	}
	else
	{
		if (ray->dir_y > 0)
			texture = game->textures.south;
		else
			texture = game->textures.north;
	}
	for (y = 0; y < ray->draw_start; y++)
		put_pixel(game->img, x, y, game->textures.ceiling_color);
	for (y = ray->draw_start; y < ray->draw_end; y++)
	{
		tex_y = (int)ray->tex_pos & (texture->height - 1);
		ray->tex_pos += ray->tex_step;
		color = get_pixel_color(texture, ray->tex_x, tex_y);
		put_pixel(game->img, x, y, color);
	}
	for (y = ray->draw_end; y < SCREEN_HEIGHT; y++)
		put_pixel(game->img, x, y, game->textures.floor_color);
}

void	clear_image(t_img *img)
{
	ft_memset(img->data, 0, SCREEN_WIDTH * SCREEN_HEIGHT * (img->bits_per_pixel
			/ 8));
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char *dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	dst = img->data + (y * img->size_line + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}