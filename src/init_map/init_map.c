/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 18:34:26 by egiubell         ###   ########.fr       */
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

void	extrapolate_map(t_game *game)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	while (game->vars->mtx[++i])
	{
		j = -1;
		while (game->vars->mtx[i][++j] && i < game->vars->mtx_line - 1)
		{
			l = 0;
			if (game->vars->mtx[i][j] == '1' && game->vars->mtx[i][j + 1] == '1'
				&& game->vars->mtx[i][j + 2] == '1' &&
				game->vars->mtx[i][j + 3] == '1')
			{
				game->vars->line = game->vars->mtx_line - i;
				game->vars->map = ft_calloc(sizeof(char *),
						(game->vars->mtx_line - i));
				while (game->vars->mtx[i])
					game->vars->map[l++] = game->vars->mtx[i++];
				game->vars->map[l--] = NULL;
				return ;
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
	game->vars->mtx = ft_calloc (sizeof(char *), game->vars->mtx_line + 1);
	while (i < game->vars->mtx_line)
	{
		str = get_next_line(fd, 0);
		game->vars->mtx[i] = str;
		i++;
	}
	close (fd);
	free_get();
	check_paths(game);
	clean_paths(game);
	check_colors(game);
	extrapolate_map(game);
	check_errors(game);
	set_player_pos(game);
	return (0);
}
