/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:22:20 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 05:18:58 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	init_struct(t_game *game)
{
	game->vars->line = 0;
	game->vars->column = 0;
	game->vars->player_n = 0;
	game->x = 0;
	game->y = 0;
	game->map_i = 0;
	game->map_j = 0;
	game->player.pos_x = 0;
	game->player.pos_y = 0;
	game->player.mov_dir = 0;
	game->x_arrow = 0;
	game->y_arrow = 0;
	game->ray_x = 0;
	game->ray_y = 0;
	game->rad_p = 0;
	game->rad_ray = 0;
	game->ray_uncasted = 0;
	game->f_mtx = NULL;
	game->c_mtx = NULL;
}

int	main(int ac, char **av)
{
	char	*path;
	t_game	game;

	game.vars = (t_vars *)malloc (sizeof (t_vars));
	check_ac(ac, &game);
	path = av[1];
	check_path(path, &game);
	init_struct(&game);
	init_map(path, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 720, 450, "cub3d");
	game.img = mlx_new_image(game.mlx, 720, 450);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	assets_init(&game);
	check_raycast(&game);
	mlx_hook(game.win, 17, 0, close_generic, &game);
	mlx_hook(game.win, 2, 1L << 0, controls_working, &game);
	mlx_key_hook(game.win, controls_working, &game);
	mlx_loop(game.mlx);
	return (0);
}
