/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:16:53 by napham            #+#    #+#             */
/*   Updated: 2025/05/30 22:33:58 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_image(t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel_color(t_img *img, int x, int y);
void	cast_rays(t_game *game);
void	move_player(t_game *game);

int	render_frame(t_game *game)
{
	clear_image(game->img);
	move_player(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
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
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	dst = img->data + (y * img->size_line + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
