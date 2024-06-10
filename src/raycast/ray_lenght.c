/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lenght.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:20 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/10 17:04:33 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
ritorna la lunghezza del ray sul primo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
il primo quadrante parte dalla retta numero 1 alla 1079
*/
double	ft_ray_lenght_to_1079(t_game *game, double q, double m)
{
	game->hypotena = -1;
	game->hypotenb = -1;
	game->newx1a = (int)ceil(game->player.pos_x);
	game->newy1b = (int)ceil(game->player.pos_y);
	ray_loop_a(game, q, m, 0);
	ray_loop_b(game, q, m, 0);
	if ((game->hypotena + game->hypotenb) == -2)
		return (0);
	if ((game->hypotenb <= game->hypotena
			|| game->hypotena < 0) && game->hypotenb >= 0)
		return (game->hypotenb);
	if (control_a(game, 0))
		return (game->hypotena);
	return (0);
}

/*
ritorna la lunghezza del ray sul secondo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
il primo quadrante parte dalla retta numero 1080 alla 2159
*/
double	ft_ray_lenght_to_2159(t_game *game, double q, double m)
{
	game->hypotena = -1;
	game->hypotenb = -1;
	game->newx1a = floor(game->player.pos_x);
	game->newy1b = ceil(game->player.pos_y);
	ray_loop_a(game, q, m, 1);
	ray_loop_b(game, q, m, 0);
	if (game->hypotena + game->hypotenb == -2)
		return (0);
	if ((game->hypotenb <= game->hypotena
			|| game->hypotena < 0) && game->hypotenb >= 0)
		return (game->hypotenb);
	if (control_a(game, 1))
		return (game->hypotena);
	return (0);
}

/*
ritorna la lunghezza del ray sul terzo quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
il primo quadrante parte dalla retta numero 2160 alla 3239
*/
double	ft_ray_lenght_to_3239(t_game *game, double q, double m)
{
	game->hypotena = -1;
	game->hypotenb = -1;
	game->newx1a = ft_floor(game->player.pos_x);
	game->newy1b = ft_floor(game->player.pos_y);
	ray_loop_a(game, q, m, 1);
	ray_loop_b(game, q, m, 1);
	if (game->hypotena + game->hypotenb == -2)
		return (0);
	if ((game->hypotenb <= game->hypotena
			|| game->hypotena < 0) && game->hypotenb >= 0)
		return (game->hypotenb);
	if (control_a(game, 1))
		return (game->hypotena);
	return (0);
}

/*
ritorna la lunghezza del ray sul quarto quadrante, setta coord ray x e y.
ovvero del punto di collisione tra ray e muro
il primo quadrante parte dalla retta numero 3240 alla 4320
*/
double	ft_ray_lenght_after_3239(t_game *game, double q, double m)
{
	game->hypotena = -1;
	game->hypotenb = -1;
	game->newx1a = ceil(game->player.pos_x);
	game->newy1b = floor(game->player.pos_y);
	ray_loop_a(game, q, m, 0);
	ray_loop_b(game, q, m, 1);
	if (game->hypotena + game->hypotenb == -2)
		return (0);
	if ((game->hypotenb <= game->hypotena
			|| game->hypotena < 0) && game->hypotenb >= 0)
		return (game->hypotenb);
	else if (control_a(game, 0))
		return (game->hypotena);
	return (0);
}
