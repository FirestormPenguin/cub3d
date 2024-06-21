/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 04:58:58 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 05:05:23 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	clean_f(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->f_mtx[i])
	{
		j = 0;
		while (game->f_mtx[i][j] && game->f_mtx[i][j] != '\n')
		{
			j++;
		}
		game->f_mtx[i][j] = '\0';
		i++;
	}
}

void	clean_c(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->c_mtx[i])
	{
		j = 0;
		while (game->c_mtx[i][j] && game->c_mtx[i][j] != '\n')
		{
			j++;
		}
		game->c_mtx[i][j] = '\0';
		i++;
	}
}

void	clean_colors(t_game *game)
{
	clean_f(game);
	clean_c(game);
}
