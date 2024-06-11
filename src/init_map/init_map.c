/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 09:52:55 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_column(char *path)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd, 0);
	while (str[i] != '\n')
	{
		i++;
	}
	while (str)
	{
		free(str);
		str = get_next_line(fd, 0);
	}
	free(str);
	close (fd);
	return (i);
}

int	count_line(char *path)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd, 0);
	while (str)
	{
		free(str);
		str = get_next_line(fd, 0);
		i++;
	}
	close (fd);
	return (i);
}

void	check_mtx(t_game *game)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	while (game->vars->mtx[++i] && i < game->vars->line - 1)
	{
		j = -1;
		while (game->vars->mtx[i][++j])
		{
			if (game->vars->mtx[i][j] == 'N' && game->vars->mtx[i][j + 1] == 'O')
			{
				while (game->vars->mtx[i][j] != '.')
					i++;
				l = 0;
				while (game->vars->mtx[i][j])
				{
					game->no[l] = game->vars->mtx[i][j];
					j++;
					l++;
				}
			}
		}
	}
}

int	init_map(char *path, t_game *game)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	game->vars->mtx_line = count_line(path);
	game->vars->mtx_column = count_column(path);
	fd = open (path, O_RDONLY);
	game->vars->mtx = malloc (sizeof(char *) * game->vars->mtx_line + 1);
	while (i < game->vars->mtx_line)
	{
		str = get_next_line(fd, 0);
		game->vars->mtx[i] = str;
		ft_printf("%s", game->vars->mtx[i]);
		i++;
	}
	ft_printf("Line: %d\nColumn: %d\n", game->vars->mtx_line, game->vars->mtx_column);
	close (fd);
	free_get();
	check_mtx(game);
	check_errors(game);
	set_player_pos(game);
	return (0);
}
