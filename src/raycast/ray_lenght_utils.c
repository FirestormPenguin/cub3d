/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lenght_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:23 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/10 17:04:39 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_floor(double i)
{
	double	d;

	d = i;
	return ((int)floor(d));
}

/*
serve per sostituire i controlli troppo lunghi,
e setta ray x e y con le coord. di a;
dir è un modificatore che può cambiere il risultato dei controlli,
il suo valore dipende dalla direzione della semiretta:
*/
int	control_a(t_game *game, int dir)
{
	if ((game->vars->map[ft_floor(game->newya)][game->newx1a - dir] == '1'))
	{
		game->ray_x = (double)game->newx1a;
		game->ray_y = game->newya;
		game->player.ab_12 = 1;
		return (1);
	}
	else
		return (0);
}

/*
serve per sostituire i controlli troppo lunghi,
e setta ray x e y con le coord. di b;
dir è un modificatore che può cambiere il risultato dei controlli,
il suo valore dipende dalla direzione della semiretta:
*/
int	control_b(t_game *game, int dir)
{
	if (((game->vars->map[game->newy1b - dir][ft_floor(game->newxb)] == '1')))
	{
		game->ray_x = game->newxb;
		game->ray_y = (double)game->newy1b;
		game->player.ab_12 = 2;
		return (1);
	}
	else
		return (0);
}

void	ray_loop_a(t_game *game, double q, double m, int dir)
{
	while (1)
	{
		game->newya = fma(m, game->newx1a, q);
		if ((game->newya <= 0.0) || (game->newx1a <= 0)
			|| (ft_floor(game->newya) > game->vars->line) || (game->newx1a
				> ((int)ft_strlen(game->vars->map[ft_floor(game->newya)]) - 1)))
		{
			game->hypotena = -1;
			return ;
		}
		if (control_a(game, dir))
		{
			game->hypotena = hypot(fabs(game->player.pos_x - game->newx1a),
					fabs(game->player.pos_y - game->newya));
			return ;
		}
		if (dir == 0)
			game->newx1a++;
		else
			game->newx1a--;
	}
}

void	ray_loop_b(t_game *game, double q, double m, int dir)
{
	while (1)
	{
		game->newxb = ((double)game->newy1b / m) - (q / m);
		if (game->newy1b <= 0 || game->newxb <= 0
			|| game->newy1b > game->vars->line || ft_floor(game->newxb)
			> (int)(ft_strlen(game->vars->map[game->newy1b]) - 1))
		{
			game->hypotenb = -1;
			break ;
		}
		if (control_b(game, dir))
		{
			game->hypotenb = hypot(fabs(game->player.pos_x - game->newxb),
					fabs(game->player.pos_y - game->newy1b));
			break ;
		}
		if (dir == 0)
			game->newy1b++;
		else
			game->newy1b--;
	}
}
