/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:27 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 07:17:37 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	assets_init(t_game *game)
{
	int	x;
	int	y;

	game->e.img = mlx_xpm_file_to_image(game->mlx, EST_IMG, &x, &y);
	game->e.addr = mlx_get_data_addr(game->e.img, &(game->e.bits),
			&(game->e.line), &(game->e.endian));
	game->n.img = mlx_xpm_file_to_image(game->mlx, NORD_IMG, &x, &y);
	game->n.addr = mlx_get_data_addr(game->n.img, &(game->n.bits),
			&(game->n.line), &(game->n.endian));
	game->s.img = mlx_xpm_file_to_image(game->mlx, SUD_IMG, &x, &y);
	game->s.addr = mlx_get_data_addr(game->s.img, &(game->s.bits),
			&(game->s.line), &(game->s.endian));
	game->w.img = mlx_xpm_file_to_image(game->mlx, WEST_IMG, &x, &y);
	game->w.addr = mlx_get_data_addr(game->w.img, &(game->w.bits),
			&(game->w.line), &(game->w.endian));
}

void	ft_floor_n_ceil(t_game *game, int col)
{
	int		i;

	i = 0;
	while (i < 225)
	{
		my_mlx_pixel_put(game, col, i, create_trgb(0, 232, 111, 19));
		i++;
	}
	while (i < 450)
	{
		my_mlx_pixel_put(game, col, i, create_trgb(0, 82, 65, 45));
		i++;
	}
}

int	get_pixel(t_game *game, int x, int y)
{
	int	*dst;

	if (game->player.nsew == 4)
		dst = (void *)game->w.addr
			+ (y * game->w.line + x * (game->w.bits / 8));
	else if (game->player.nsew == 2)
		dst = (void *)game->s.addr
			+ (y * game->s.line + x * (game->s.bits / 8));
	else if (game->player.nsew == 1)
		dst = (void *)game->n.addr
			+ (y * game->n.line + x * (game->n.bits / 8));
	else
		dst = (void *)game->e.addr
			+ (y * game->e.line + x * (game->e.bits / 8));
	return (*(int *)dst);
}

void	ft_fakeray(t_game *game, int i)
{
	int		p;
	int		x;
	int		color;
	double	point;
	double	image_part;

	p = (623.25 / game->ray_lenght);
	ft_floor_n_ceil(game, i);
	point = game->ray_x - floor(game->ray_x);
	if (game->player.ab_12 == 1)
		point = game->ray_y - floor(game->ray_y);
	x = (int)(point / 0.015625);
	image_part = (p * 1.0) / 64;
	if (p > 450)
		p = 450;
	p = p / 2;
	color = get_pixel(game, x, 63);
	my_mlx_pixel_put(game, i, 225 + p, color);
	while (--p >= 0)
	{
		color = get_pixel(game, x, (int)round(32 + (int)(p / image_part)));
		my_mlx_pixel_put(game, i, 225 + p, color);
		color = get_pixel(game, x, (int)round(32 - (int)(p / image_part)));
		my_mlx_pixel_put(game, i, 225 - p, color);
	}
}
