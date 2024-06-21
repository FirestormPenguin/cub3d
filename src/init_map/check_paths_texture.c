/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 04:12:25 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 04:18:51 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_path_no(t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buf;

	fd = open (game->no, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\npath texture not valid!\n");
		free_vars(game);
		exit(1);
	}
	bytes_read = read(fd, &buf, 1);
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error\n'%s' is a directory\n", game->no);
		close(fd);
		free_vars(game);
		exit(1);
	}
	close (fd);
}

void	check_path_so(t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buf;

	fd = open (game->so, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\npath texture not valid!\n");
		free_vars(game);
		exit(1);
	}
	bytes_read = read(fd, &buf, 1);
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error\n'%s' is a directory\n", game->so);
		close(fd);
		free_vars(game);
		exit(1);
	}
	close (fd);
}

void	check_path_ea(t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buf;

	fd = open (game->ea, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\npath texture not valid!\n");
		free_vars(game);
		exit(1);
	}
	bytes_read = read(fd, &buf, 1);
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error\n'%s' is a directory\n", game->ea);
		close(fd);
		free_vars(game);
		exit(1);
	}
	close (fd);
}

void	check_path_we(t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buf;

	fd = open (game->we, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\npath texture not valid!\n");
		free_vars(game);
		exit(1);
	}
	bytes_read = read(fd, &buf, 1);
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error\n'%s' is a directory\n", game->we);
		close(fd);
		free_vars(game);
		exit(1);
	}
	close (fd);
}

void	check_paths_texture(t_game *game)
{
	check_path_no(game);
	check_path_so(game);
	check_path_ea(game);
	check_path_we(game);
}
