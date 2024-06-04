/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:58:19 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/04 02:00:57 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_get(void)
{
	char	*str_free_get;

	str_free_get = get_next_line(0, 1);
}

void	free_vars(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->vars->line)
	{
		free(game->vars->map[i]);
		game->vars->map[i] = NULL;
		i++;
	}
	free(game->vars->map);
	free(game->vars);
}

int	close_generic(t_game *game)
{
	free_vars(game);
	ft_printf("EXIT\n");
	exit(0);
}
