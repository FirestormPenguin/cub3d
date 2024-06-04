/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:19:21 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/04 03:31:47 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_player_view(t_game *game, t_vec2 pos)
{
	char	dir;

	dir = game->vars->map[(int)pos.y][(int)pos.x];
	if (dir == 'N')
	{
		game->player.dir.y = -1.0;
		game->player.plane.x = 0.66;
	}
	else if (dir == 'S')
	{
		game->player.dir.y = 1.0;
		game->player.plane.x = -0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir.x = -1.0;
		game->player.plane.y = -0.66;
	}
	else if (dir == 'E')
	{
		game->player.dir.x = 1.0;
		game->player.plane.y = 0.66;
	}
}

int	find_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->vars->map[++y])
	{
		x = -1;
		while (game->vars->map[y][++x])
		{
			if (ft_strchr2("NSWE", game->vars->map[y][x]))
			{
				game->vars->player_pos.x = x;
				game->vars->player_pos.y = y;
				ft_printf("Player pos 1:\nx: %d\ny: %d\n\n", x, y);
				ft_printf("Player pos 2:\nx: %d\ny: %d\n\n", game->vars->player_pos.x, game->vars->player_pos.y);
				return (1);
			}
		}
	}
	return (0);
}

int	init_player(t_game *game)
{
	find_player_pos(game);
	game->player.pos.x = (int)game->vars->player_pos.x;
	game->player.pos.y = (int)game->vars->player_pos.y;
	game->player.dir.x = 0.0;
	game->player.dir.y = 0.0;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.0;
	game->player.mov_dir.x = 0;
	game->player.mov_dir.y = 0;
	game->player.rot_dir = 0;
	set_player_view(game, game->vars->player_pos);
	game->vars->map[(int)game->vars->player_pos.y][
		(int)game->vars->player_pos.x] = '0';
	ft_printf("Player pos 3:\nx: %d\ny: %d\n", game->player.pos.x, game->player.pos.y);
	return (0);
}
