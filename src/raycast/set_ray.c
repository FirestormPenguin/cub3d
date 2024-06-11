/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:31 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 07:08:55 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* colacola la distanza tra il punto del muro e il PIANO del giocatore,
quindi evita il fisheye effect.
Hypo = la distanza effettiva tra punto e giocatore,
quindi il ray trovato prima. */
double	ft_ray_on_plane(t_game *game, double hypo_lenght)
{
	double	rad_hyp;

	rad_hyp = game->rad_ray - game->rad_p;
	if (rad_hyp > PI / 2)
		rad_hyp = game->rad_p + PI - game->rad_ray;
	return (sin(rad_hyp) * hypo_lenght);
}

/* setta il ray nel caso in cui la retta sia direzionata
sul primo quadrante */
void	ft_set_ray_to_1079(t_game *game, double q, double m, int i)
{
	game->ray_lenght = ft_ray_on_plane(game,
			ft_ray_lenght_to_1079(game, q, m));
	if (game->player.ab_12 == 1)
		game->player.nsew = 3;
	else
		game->player.nsew = 1;
	ft_fakeray(game, i);
}

/* setta il ray nel caso in cui la retta sia direzionata
sul secondo quadrante */
void	ft_set_ray_to_2159(t_game *game, double q, double m, int i)
{
	game->ray_lenght = ft_ray_on_plane(game,
			ft_ray_lenght_to_2159(game, q, m));
	if (game->player.ab_12 == 1)
		game->player.nsew = 4;
	else
		game->player.nsew = 1;
	ft_fakeray(game, i);
}

/* setta il ray nel caso in cui la retta sia direzionata
sul terzo quadrante */
void	ft_set_ray_to_3239(t_game *game, double q, double m, int i)
{
	game->ray_lenght = ft_ray_on_plane(game,
			ft_ray_lenght_to_3239(game, q, m));
	if (game->player.ab_12 == 1)
		game->player.nsew = 4;
	else
		game->player.nsew = 2;
	ft_fakeray(game, i);
}

/* setta il ray nel caso in cui la retta sia direzionata
sul quarto quadrante */
void	ft_set_ray_after_3239(t_game *game, double q, double m, int i)
{
	game->ray_lenght = ft_ray_on_plane(game,
			ft_ray_lenght_after_3239(game, q, m));
	if (game->player.ab_12 == 1)
		game->player.nsew = 3;
	else
		game->player.nsew = 2;
	ft_fakeray(game, i);
}
