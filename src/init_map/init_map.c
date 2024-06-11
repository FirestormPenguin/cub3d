/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 07:03:50 by egiubell         ###   ########.fr       */
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

int	init_map(char *path, t_game *game)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	game->vars->line = count_line(path);
	game->vars->column = count_column(path);
	fd = open (path, O_RDONLY);
	game->vars->map = malloc (sizeof(char *) * game->vars->line + 1);
	while (i < game->vars->line)
	{
		str = get_next_line(fd, 0);
		game->vars->map[i] = str;
		ft_printf("%s", game->vars->map[i]);
		i++;
	}
	ft_printf("Line: %d\nColumn: %d\n", game->vars->line, game->vars->column);
	close (fd);
	free_get();
	check_errors(game);
	set_player_pos(game);
	return (0);
}
