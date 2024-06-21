/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:12:39 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 05:19:09 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_f(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][++j])
		{
			if (game->vars->mtx[i][j] == 'F' &&
				game->vars->mtx[i][j + 1] == ' ')
			{
				j += 2;
				while (game->vars->mtx[i][j] != '\n' &&
					game->vars->mtx[i][j] <= '0'
					&& game->vars->mtx[i][j] >= '9')
					j++;
				game->f = &game->vars->mtx[i][j];
				return ;
			}
		}
	}
	error(game, 4);
}

void	check_c(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][++j])
		{
			if (game->vars->mtx[i][j] == 'C' &&
				game->vars->mtx[i][j + 1] == ' ')
			{
				j += 2;
				while (game->vars->mtx[i][j] != '\n' &&
					game->vars->mtx[i][j] <= '0'
					&& game->vars->mtx[i][j] >= '9')
					j++;
				game->c = &game->vars->mtx[i][j];
				return ;
			}
		}
	}
	error(game, 4);
}

void	check_colors(t_game *game)
{
	int	i;

	i = 0;
	check_f(game);
	check_c(game);
	game->f_mtx = ft_split(game->f, ',');
	game->c_mtx = ft_split(game->c, ',');
	while (game->f_mtx[i] && game->c_mtx[i])
		i++;
	if (i < 3)
		error(game, 5);
	clean_colors(game);
	if (ft_isdigit(game->f_mtx) || ft_isdigit(game->c_mtx))
		error(game, 5);
	if (ft_isrgb(game->f_mtx) || ft_isrgb(game->c_mtx))
		error(game, 5);
}
