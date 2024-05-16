/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2024/05/16 17:29:00 by egiubell         ###   ########.fr       */
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
		ft_printf("Too much players characters\n");
	free_vars(game);
	exit(0);
}

void	check_full(t_game *game, int i, int j, char **tmp_map)
{
	if (game->vars->map[i + 1][j] && game->vars->map[i + 1][j] != '1' && tmp_map[i + 1][j] != '0')
	{
		tmp_map[i + 1][j] = '0';
		check_full(game, i + 1, j, tmp_map);
	}
	if (game->vars->map[i - 1][j] && game->vars->map[i - 1][j] != '1' && tmp_map[i - 1][j] != '0')
	{
		tmp_map[i - 1][j] = '0';
		check_full(game, i - 1, j, tmp_map);
	}
	if (game->vars->map[i][j + 1] && game->vars->map[i][j + 1] != '1' && tmp_map[i][j + 1] != '0')
	{
		tmp_map[i][j + 1] = '0';
		check_full(game, i, j + 1, tmp_map);
	}
	if (game->vars->map[i][j - 1]&& game->vars->map[i][j - 1] != '1' && tmp_map[i][j - 1] != '0')
	{
		tmp_map[i][j - 1] = '0';
		check_full(game, i, j - 1, tmp_map);
	}

	if (game->vars->map[i][j] != '0'
		&& game->vars->map[i][j] != '1'
		&& game->vars->map[i][j] != 'N'
		&& game->vars->map[i][j] != 'S'
		&& game->vars->map[i][j] != 'E'
		&& game->vars->map[i][j] != 'W'
		&& game->vars->map[i][j] != ' ')
		tmp_map[i][j] = '0';
	else
		tmp_map[i][j] = '1';

}

void	check_edges(t_game *game, int i, int j)
{
	char **tmp_map;
	int i1;
	int j1;

	tmp_map = malloc (sizeof(char *) * game->vars->line + 1);
	i1 = 0;
	while (tmp_map[i1])
	{
		tmp_map[i1] = malloc (sizeof(char) * game->vars->column + 1);
		i1++;
	}
	if (game->vars->map[i][j + 1] != '1' && game->vars->map[i][j + 1] != ' ')
		check_full(game, i , j, tmp_map);
	else if (game->vars->map[i + 1][j] != '1' && game->vars->map[i + 1][j] != ' ')
		check_full(game, i , j, tmp_map);
	else if (game->vars->map[i + 1][j + 1] != '1' && game->vars->map[i + 1][j + 1] != ' ')
		check_full(game, i, j, tmp_map);

	i1 = 0;
	j1 = 0;
	while (tmp_map[i1])
	{
		while (tmp_map[i1][j1])
		{
			if (tmp_map[i1][j1] == 0)
				error(game, 1);
			j1++;
		}
		i1++;
	}
}

void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->vars->map[i])
	{
		j = 0;
		while (game->vars->map[i][j])
		{
			if (game->vars->map[i][j] == '\n')
				break ;
			if (game->vars->map[i][j] == 'N' || game->vars->map[i][j] == 'S'
				|| game->vars->map[i][j] == 'E' || game->vars->map[i][j] == 'W')
				game->vars->player++;
			if (game->vars->map[i][j] != '0' && game->vars->map[i][j] != '1'
					&& game->vars->map[i][j] != 'N' && game->vars->map[i][j] != 'S'
					&& game->vars->map[i][j] != 'E' && game->vars->map[i][j] != 'W'
					&& game->vars->map[i][j] != ' ')
				{
					ft_printf("Found correct, position [%d][%d]\n", i, j);
					error(game, 2);
				}
			j++;
		}
		i++;
	}
	if (game->vars->player < 1 || game->vars->player > 1)
		error(game, 3);
}

void	check_errors(t_game *game)
{
	int i;
	int j;

	while (i < game->vars->line)
	{
		j = 0;
		while (j < game->vars->column)
		{
			if (game->vars->map[i][j] == '1')
				check_edges(game, i , j);
			j++;
		}
		i++;
	}
	check_characters(game);
}
