/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:14 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 02:18:55 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* trova m e q di un ray, smista il ray in base alla sua direzione ed
esegue una funzione a parte, ne esiste una per ogni direzione.
i numeri sono in ordine di quadrante, il piano e' diviso in 4320 rette
(720 è la risoluzione, 720 * (360 / 60) = 4320)
cosi è come se ogni direzione avesse un radiante "pre-assegnato" */
void	ft_ray_in_plane(t_game *game, int i)
{
	double	m;
	double	q;

	m = tan(game->rad_ray);
	q = game->player.pos_y - (m * game->player.pos_x);
	if (game->player.mov_dir <= 1079)
		ft_set_ray_to_1079(game, q, m, i);
	else if (game->player.mov_dir <= 2159)
		ft_set_ray_to_2159(game, q, m, i);
	else if (game->player.mov_dir <= 3239)
		ft_set_ray_to_3239(game, q, m, i);
	else
		ft_set_ray_after_3239(game, q, m, i);
}

/* controlla ogni singolo ray per un totale di 720 per frame */
void	check_raycast(t_game *game)
{
	int	i;

	i = -1;
	game->player.mov_dir = game->player.last_mov_dir;
	game->rad_p = (game->player.mov_dir * CONST_RAD
			+ (CONST_RAD / 2.0)) - 1.0471975511;
	while (++i < 720)
	{
		game->player.nsew = 0;
		game->rad_ray = game->player.mov_dir * CONST_RAD + (CONST_RAD / 2.0);
		if (game->player.mov_dir == 4320)
			game->player.mov_dir = 0;
		ft_ray_in_plane(game, i);
		game->player.mov_dir++;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img, 0, 0);
}
