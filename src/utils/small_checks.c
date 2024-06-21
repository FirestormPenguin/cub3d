/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:02:51 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 05:31:37 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_path(char *path, t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buf;

	fd = open (path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nPath not valid!\n");
		free(game->vars);
		exit(1);
	}
	bytes_read = read(fd, &buf, 1);
	if (bytes_read == -1)
	{
		ft_printf("Error\n'%s' is a directory\n", path);
		close(fd);
		free(game->vars);
		exit(1);
	}
	close (fd);
}

void	check_ac(int ac, t_game *game)
{
	if (ac != 2)
	{
		free(game->vars);
		ft_printf("Error\nNumber of vars invalid, insert the map path!\n");
		exit (1);
	}
}
