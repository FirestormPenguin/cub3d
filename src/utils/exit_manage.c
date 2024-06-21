/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:58:19 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 13:10:32 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mtx_len(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		i++;
	return (i);
}

void	free_get(void)
{
	char	*str_free_get;

	str_free_get = get_next_line(0, 1);
}

void	free_mtx_colors(t_game *game)
{
	if (game->f_mtx)
	{
		if (mtx_len(game->f_mtx) <= 3 && game->f_mtx[0])
			free(game->f_mtx[0]);
		if (mtx_len(game->f_mtx) <= 3 && game->f_mtx[1])
			free(game->f_mtx[1]);
		if (mtx_len(game->f_mtx) <= 3 && game->f_mtx[2])
			free(game->f_mtx[2]);
		free(game->f_mtx);
	}
	if (game->c_mtx)
	{
		if (mtx_len(game->c_mtx) <= 3 && game->c_mtx[0])
			free(game->c_mtx[0]);
		if (mtx_len(game->c_mtx) <= 3 && game->c_mtx[1])
			free(game->c_mtx[1]);
		if (mtx_len(game->c_mtx) == 3 && game->c_mtx[2])
			free(game->c_mtx[2]);
		free(game->c_mtx);
	}
}

void	free_vars(t_game *game)
{
	int	i;

	i = 0;
	while (game->vars->mtx[i])
	{
		free(game->vars->mtx[i]);
		game->vars->mtx[i] = NULL;
		i++;
	}
	free(game->vars->mtx);
	if (game->vars->map)
		free(game->vars->map);
	free(game->vars);
	free_mtx_colors(game);
}

int	close_generic(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	free_vars(game);
	ft_printf("EXIT\n");
	exit(0);
}
