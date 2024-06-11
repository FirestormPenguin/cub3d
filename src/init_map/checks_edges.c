/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:50:09 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 16:34:04 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_empty_space(t_game *game, int i, int j)
{
	if (!game->vars->map[i + 1][j] || game->vars->map[i + 1][j] == '\0'
		|| game->vars->map[i + 1][j] == ' '
		|| game->vars->map[i + 1][j] == '\n')
		error(game, 1);
	if (!game->vars->map[i - 1][j] && game->vars->map[i - 1][j] == '\0'
		|| game->vars->map[i - 1][j] == ' '
		|| game->vars->map[i - 1][j] == '\n')
		error(game, 1);
	if (!game->vars->map[i][j + 1] && game->vars->map[i][j + 1] == '\0'
		|| game->vars->map[i][j + 1] == ' '
		|| game->vars->map[i][j + 1] == '\n')
		error(game, 1);
	if (!game->vars->map[i][j - 1] && game->vars->map[i][j - 1] == '\0'
		|| game->vars->map[i][j - 1] == ' '
		|| game->vars->map[i][j - 1] == '\n')
		error(game, 1);
}

void	check_edges(t_game *game, int i, int j)
{
	check_empty_space(game, i, j);
	if (game->vars->map[i + 1][j] && game->vars->map[i + 1][j] == '0'
		&& game->vars->map[i + 1][j] != 'C')
	{
		game->vars->map[i + 1][j] = 'C';
		check_edges(game, i + 1, j);
	}
	if (game->vars->map[i - 1][j] && game->vars->map[i - 1][j] == '0'
		&& game->vars->map[i - 1][j] != 'C')
	{
		game->vars->map[i - 1][j] = 'C';
		check_edges(game, i - 1, j);
	}
	if (game->vars->map[i][j + 1] && game->vars->map[i][j + 1] == '0'
		&& game->vars->map[i][j + 1] != 'C')
	{
		game->vars->map[i][j + 1] = 'C';
		check_edges(game, i, j + 1);
	}
	if (game->vars->map[i][j - 1] && game->vars->map[i][j - 1] == '0'
		&& game->vars->map[i][j - 1] != 'C')
	{
		game->vars->map[i][j - 1] = 'C';
		check_edges(game, i, j - 1);
	}
}
