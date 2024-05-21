/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2024/05/21 23:30:26 by egiubell         ###   ########.fr       */
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
		printf("position %s\n", game->vars->map[i]);
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
					error(game, 2);
			j++;
		}
		i++;
	}
	if (game->vars->player < 1 || game->vars->player > 1)
		error(game, 3);
}

int	check_edges(t_game *game, char **map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("0NSWEDO", map[y][x]) && ((!y || !x || !map[y + 1]
				|| (x && (map[y][x - 1] == ' ' || map[y][x - 1] == '\0'))
						|| (x < ft_strlen(map[y]) && (map[y][x + 1] == ' '
							|| map[y][x + 1] == '\0')))
					|| ((y && x < (ft_strlen(map[y - 1]) - 1) && (map[y - 1][x]
						== ' ' || map[y - 1][x] == '\0')) || (map[y + 1]
						&& (x > (ft_strlen(map[y + 1]) - 1) || (map[y + 1][x]
						== ' ' || map[y + 1][x] == '\0'))))))
				error(game, 1);
		}
	}
	return (0);
}

void	check_errors(t_game *game)
{
	int i;
	int j;

	check_edges(game, game->vars->map);
	check_characters(game);
}
