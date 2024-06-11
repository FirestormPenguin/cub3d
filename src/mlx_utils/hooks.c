/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:52:04 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 01:48:02 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_a(t_game *game)
{
	double	x;
	double	y;
	double	angle;

	angle = game->player.mov_dir * CONST_RAD - (PI / 2) - (PI / 6);
	x = game->player.pos_x + 0.211 * cos(angle);
	y = game->player.pos_y + 0.211 * sin(angle);
	if (game->vars->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	game->player.pos_x = x;
	game->player.pos_y = y;
	check_raycast(game);
	return (0);
}

int	ft_w(t_game *game)
{
	double	x;
	double	y;
	double	angle;

	angle = game->player.mov_dir * CONST_RAD - (PI / 6);
	x = game->player.pos_x + 0.211 * cos(angle);
	y = game->player.pos_y + 0.211 * sin(angle);
	if (game->vars->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	game->player.pos_x = x;
	game->player.pos_y = y;
	check_raycast(game);
	return (0);
}

int	ft_s(t_game *game)
{
	double	x;
	double	y;
	double	angle;

	angle = game->player.mov_dir * CONST_RAD - (PI / 6);
	x = game->player.pos_x - 0.211 * cos(angle);
	y = game->player.pos_y - 0.211 * sin(angle);
	if (game->vars->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	game->player.pos_x = x;
	game->player.pos_y = y;
	check_raycast(game);
	return (0);
}

int	ft_d(t_game *game)
{
	double	x;
	double	y;
	double	angle;

	angle = game->player.mov_dir * CONST_RAD - (PI / 2) - (PI / 6);
	x = game->player.pos_x - 0.211 * cos(angle);
	y = game->player.pos_y - 0.211 * sin(angle);
	if (game->vars->map[ft_floor(y)][ft_floor(x)] == '1')
		return (0);
	game->player.pos_x = x;
	game->player.pos_y = y;
	check_raycast(game);
	return (0);
}

int	controls_working(int command, t_game *game)
{
	if (command == ESC)
		close_generic(game);
	if (command == A)
		ft_a(game);
	if (command == D)
		ft_d(game);
	if (command == S)
		ft_s(game);
	if (command == W)
		ft_w(game);
	if (command == LEFT)
	{
		game->player.last_mov_dir -= 8;
		if (game->player.last_mov_dir <= 0)
			game->player.last_mov_dir = 4320;
		check_raycast(game);
	}
	if (command == RIGHT)
	{
		game->player.last_mov_dir += 8;
		if (game->player.last_mov_dir >= 4320)
			game->player.last_mov_dir = 0;
		check_raycast(game);
	}
	return (1);
}
