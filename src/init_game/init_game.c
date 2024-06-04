/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 02:49:50 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/04 03:01:41 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_game(t_game *game)
{
	init_player(game);
	// game->mlx = mlx_init();
	// game->win = mlx_new_window(game->mlx, 1280, 720, "cub3D");
	// // game->screen.img = mlx_new_image(game->mlx, 1280, 720);
	// // game->screen.addr = mlx_get_data_addr(game->screen.img,
	// // 		&game->screen.bits_per_pixel, &game->screen.line_length,
	// // 		&game->screen.endian);
	// init_wall_textures(game);
	// init_door_textures(game);
	// init_minimap(game);
}