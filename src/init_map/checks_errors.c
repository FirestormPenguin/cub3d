/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 16:54:38 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error(t_game *game, int id)
{
	ft_printf ("Error\n");
	if (id == 1)
		ft_printf("Edges not valid\n");
	else if (id == 2)
		ft_printf("Found invalid character\n");
	else if (id == 3)
		ft_printf("Too much or not enough players characters\n");
	else if (id == 4)
		ft_printf("No path found\n");
	free_vars(game);
	exit(0);
}

void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->map[++i] && i < game->vars->line - 1)
	{
		j = -1;
		while (game->vars->map[i][++j])
		{
			if (game->vars->map[i][j] == '\n')
				break ;
			if (game->vars->map[i][j] == 'N' || game->vars->map[i][j] == 'S'
				|| game->vars->map[i][j] == 'E' || game->vars->map[i][j] == 'W')
				game->vars->player_n++;
			if (game->vars->map[i][j] != '0' && game->vars->map[i][j] != '1'
					&& game->vars->map[i][j] != 'N'
					&& game->vars->map[i][j] != 'S'
					&& game->vars->map[i][j] != 'E'
					&& game->vars->map[i][j] != 'W'
					&& game->vars->map[i][j] != ' ')
				error(game, 2);
		}
	}
	if (game->vars->player_n < 1 || game->vars->player_n > 1)
		error(game, 3);
}

void	decheck_mtx(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->map[++i] && i < game->vars->line - 1)
	{
		j = -1;
		while (game->vars->map[i][++j])
		{
			if (game->vars->map[i][j] == 'C')
				game->vars->map[i][j] = '0';
		}
	}
}

void	first_last_check(t_game *game)
{
	int	i;
	int	n;

	n = game->vars->line - 1;
	i = 0;
	while (game->vars->map[0][i] != '\n')
	{
		if (game->vars->map[0][i] != '1' && game->vars->map[0][i] != ' ')
			error(game, 1);
		i++;
	}
	i = 0;
	while (game->vars->map[n][i] != '\n')
	{
		if (game->vars->map[n][i] != '1' && game->vars->map[n][i] != ' ')
			error(game, 1);
		i++;
	}
}

void	check_errors(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	first_last_check(game);
	while (game->vars->map[++i] && i < game->vars->line - 1)
	{
		j = -1;
		while (game->vars->map[i][++j])
		{
			if (game->vars->map[i][j] == '0' || game->vars->map[i][j] == 'N'
				|| game->vars->map[i][j] == 'S' || game->vars->map[i][j] == 'E'
				|| game->vars->map[i][j] == 'W')
				check_edges(game, i, j);
		}
	}
	decheck_mtx(game);
	check_characters(game);
}
