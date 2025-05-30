/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:29:17 by napham            #+#    #+#             */
/*   Updated: 2025/05/30 22:34:30 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel_color(t_img *img, int x, int y);

static t_img	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (game->textures.east);
		return (game->textures.west);
	}
	if (ray->dir_y > 0)
		return (game->textures.south);
	return (game->textures.north);
}

static void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		put_pixel(game->img, x, y, game->map->ceiling_color);
		y++;
	}
}

static void	draw_wall_segment(t_game *game, t_ray *ray, int x, t_img *texture)
{
	int	y;
	int	tex_y;
	int	color;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)ray->tex_pos & (texture->height - 1);
		ray->tex_pos += ray->tex_step;
		color = get_pixel_color(texture, ray->tex_x, tex_y);
		put_pixel(game->img, x, y, color);
		y++;
	}
}

static void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < SCREEN_HEIGHT)
	{
		put_pixel(game->img, x, y, game->map->floor_color);
		y++;
	}
}

void	render_wall(t_game *game, t_ray *ray, int x)
{
	t_img	*texture;

	texture = get_wall_texture(game, ray);
	draw_ceiling(game, x, ray->draw_start);
	draw_wall_segment(game, ray, x, texture);
	draw_floor(game, x, ray->draw_end);
}
