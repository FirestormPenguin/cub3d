/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2024/04/23 17:05:22 by egiubell         ###   ########.fr       */
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
	str = get_next_line(fd);
	while (str[i] != '\n')
	{
		i++;
	}
	while (str)
	{
		free(str);
		str = get_next_line(fd);
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
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close (fd);
	return (i);
}

int	get_map(char *path, t_game *game)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	game->vars->line = count_line(path);
	game->vars->column = count_column(path);
	if (!(fd = open(path, O_RDONLY)))
	{
		ft_printf("Map not valid!\n");
		exit(1);
	}
	game->vars->map = malloc (sizeof(char *) * game->vars->line + 1);
	while (i < game->vars->line)
	{
		str = get_next_line(fd);
		game->vars->map[i] = str;
		ft_printf("%s", game->vars->map[i]);
		i++;
	}
	ft_printf("Line: %d\nColumn: %d\n", game->vars->line, game->vars->column);
	close (fd);
	check_errors(game);
	return (0);
}
