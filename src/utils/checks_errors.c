/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:02 by egiubell         ###   ########.fr       */
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
				ft_printf("invalid character in position x: %d y: %d\n", i, j);
				error(game, 2);
			}
			j++;
		}
		i++;
	}
	if (game->vars->player < 1 || game->vars->player > 1)
		error(game, 3);
}

void decheck_mtx(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->map[++i])
	{
		j = -1;
		while (game->vars->map[i][++j])
		{
			if (game->vars->map[i][j] == 'C')
				game->vars->map[i][j] = '0';
		}
	}
}

void	check_errors(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (game->vars->map[++i])
	{
		j = -1;
		while (game->vars->map[i][++j])
		{
			if (game->vars->map[i][j] == '0' || game->vars->map[i][j] == 'N'
				|| game->vars->map[i][j] == 'S' || game->vars->map[i][j] == 'E'
				|| game->vars->map[i][j] == 'W')
				check_edges(game, i , j);
		}
	}
	check_characters(game);
	decheck_mtx(game);
}
