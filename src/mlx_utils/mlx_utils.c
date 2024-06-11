/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:08:01 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 01:10:08 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (y >= 450 || y < 0)
		return (0);
	dst = game->addr + (y * game->line_length
			+ x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	iswhite(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	else
		return (0);
}
