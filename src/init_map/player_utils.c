/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:05:21 by jcardina          #+#    #+#             */
/*   Updated: 2024/06/11 01:37:26 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	player_dir(t_game *game, char c)
{
	if (c == 'W')
		game->player.last_mov_dir = 1800;
	else if (c == 'E')
		game->player.last_mov_dir = 3960;
	else if (c == 'N')
		game->player.last_mov_dir = 2880;
	else if (c == 'S')
		game->player.last_mov_dir = 720;
}

void	set_player_pos(t_game *game)
{
	int	y;
	int	x;
	int	flag;

	y = -1;
	flag = 0;
	while (game->vars->map[++y])
	{
		x = 0;
		while (game->vars->map[y][x])
		{
			if (game->vars->map[y][x] == 'N' || game->vars->map[y][x] == 'S'
				|| game->vars->map[y][x] == 'E' || game->vars->map[y][x] == 'W')
			{
				if (flag == 1)
					return ;
				game->player.pos_x = (float)(x + 0.5);
				game->player.pos_y = y + 0.5;
				player_dir(game, game->vars->map[y][x]);
				flag = 1;
			}
			x++;
		}
	}
	return ;
}
