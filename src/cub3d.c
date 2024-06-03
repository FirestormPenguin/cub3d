/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:22:20 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/04 01:56:44 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_struct(t_game *game)
{
	game->vars->line = 0;
	game->vars->column = 0;
	game->vars->player = 0;
	game->x = 0;
	game->y = 0;
	game->map_i = 0;
	game->map_j = 0;
	game->x_arrow = 0;
	game->y_arrow = 0;
	game->move_count = 0;
	game->ammo_count = 0;
	game->monster_animation_timer = 0;
	game->monster_frame = 0;
}

void	check_path(char *path, t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buf;

	fd = open (path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: path not valid!\n");
		free(game->vars);
		exit(1);
	}
	bytes_read = read(fd, &buf, 1);
	if (bytes_read == -1)
	{
		fprintf(stderr, "Error: '%s' is a directory\n", path);
		close(fd);
		free(game->vars);
		exit(1);
	}
	close (fd);
}

int	main(int ac, char **av)
{
	char	*path;
	t_game	game;
	int		fd;

	game.vars = (t_vars *)malloc (sizeof (t_vars));
	if (ac != 2)
	{
		free(game.vars);
		return (printf("Number of vars invalid, insert the map path!\n"), 0);
	}
	path = av[1];
	check_path(path, &game);
	init_struct(&game);
	init_map(path, &game);
	free_vars(&game);
}
