/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:20:14 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 17:55:09 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	clean_no(t_game *game)
{
	int	i;

	i = 0;
	while (game->no[i] != '\n')
	{
		i++;
	}
	game->no[i] = '\0';
}

void	clean_so(t_game *game)
{
	int	i;

	i = 0;
	while (game->so[i] != '\n')
	{
		i++;
	}
	game->so[i] = '\0';
}

void	clean_ea(t_game *game)
{
	int	i;

	i = 0;
	while (game->ea[i] != '\n')
	{
		i++;
	}
	game->ea[i] = '\0';
}

void	clean_we(t_game *game)
{
	int	i;

	i = 0;
	while (game->we[i] != '\n')
	{
		i++;
	}
	game->we[i] = '\0';
}

void	clean_paths(t_game *game)
{
	clean_no(game);
	clean_so(game);
	clean_ea(game);
	clean_we(game);
}
