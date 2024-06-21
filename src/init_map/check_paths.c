/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:05:50 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 12:43:56 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_no(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][j + 1] && game->vars->mtx[i][++j] != '\n')
		{
			if (game->vars->mtx[i][j] == 'N' &&
				game->vars->mtx[i][j + 1] == 'O')
			{
				while (game->vars->mtx[i][j] != '\n')
				{
					if (game->vars->mtx[i][j] == '.')
					{
						game->no = &game->vars->mtx[i][j];
						return ;
					}
					j++;
				}
			}
		}
	}
	error(game, 4);
}

void	check_so(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][j + 1] && game->vars->mtx[i][++j] != '\n')
		{
			if (game->vars->mtx[i][j] == 'S' &&
				game->vars->mtx[i][j + 1] == 'O')
			{
				while (game->vars->mtx[i][j] != '\n')
				{
					if (game->vars->mtx[i][j] == '.')
					{
						game->so = &game->vars->mtx[i][j];
						return ;
					}
					j++;
				}
			}
		}
	}
	error(game, 4);
}

void	check_ea(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][j + 1] && game->vars->mtx[i][++j] != '\n')
		{
			if (game->vars->mtx[i][j] == 'E' &&
				game->vars->mtx[i][j + 1] == 'A')
			{
				while (game->vars->mtx[i][j] != '\n')
				{
					if (game->vars->mtx[i][j] == '.')
					{
						game->ea = &game->vars->mtx[i][j];
						return ;
					}
					j++;
				}
			}
		}
	}
	error(game, 4);
}

void	check_we(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][j + 1] && game->vars->mtx[i][++j] != '\n')
		{
			if (game->vars->mtx[i][j] == 'W' &&
				game->vars->mtx[i][j + 1] == 'E')
			{
				while (game->vars->mtx[i][j] != '\n')
				{
					if (game->vars->mtx[i][j] == '.')
					{
						game->we = &game->vars->mtx[i][j];
						return ;
					}
					j++;
				}
			}
		}
	}
	error(game, 4);
}

void	check_paths(t_game *game)
{
	check_no(game);
	check_so(game);
	check_ea(game);
	check_we(game);
}
