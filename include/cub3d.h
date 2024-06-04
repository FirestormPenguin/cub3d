/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:22:24 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/04 03:31:44 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../src/get_next_line/get_next_line.h"
# include "../src/ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	mov_dir;
	double	rot_dir;
	t_vec2	plane;
	t_vec2	mov_speed;
	double	rot_speed;
}	t_player;

typedef struct s_vars
{
	char	**map;
	int		line;
	int		column;
	int		player_n;
	t_vec2	player_pos;
}	t_vars;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_vars		*vars;
	t_player	player;
	int			x;
	int			y;
	int			map_i;
	int			map_j;
	int			x_arrow;
	int			y_arrow;
	int			move_count;
	int			ammo_count;
	double		monster_animation_timer;
	int			monster_frame;
}	t_game;

# define TERRAIN	"./assets/terrain.xpm"

# define W 119
# define A 97
# define D 100
# define S 115
# define ESC 65307
# define TILESIZE 128

# define FRAMERATE 60
# define ANIMATIONDELAY 10000

/*small checks*/
void	check_path(char *path, t_game *game);
void	check_ac(int ac, t_game *game);

/*utils*/
char	*ft_itoa(int n);
char	*ft_strchr2(const char *s, int c);

/*init map*/
int		init_map(char *path, t_game *game);
int		count_line(char *path);
int		count_column(char *path);

/*checks_errors*/
void	check_errors(t_game *game);
void	check_edges(t_game *game, int i, int j);
void	checks_vars(t_game *game);
void	error(t_game *game, int id);

/*init_player*/
void	init_game(t_game *game);
int		init_player(t_game *game);

/*exit_manage*/
int		close_generic(t_game *game);
void	free_vars(t_game *game);
void	free_get(void);

#endif
