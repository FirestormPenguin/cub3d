/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:22:24 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/11 17:46:10 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../src/get_next_line/get_next_line.h"
# include "../src/ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mov_dir;
	double	last_mov_dir;
	int		ab_12;
	int		nsew;
}	t_player;

typedef struct s_vars
{
	char	**mtx;
	int		mtx_line;
	int		mtx_column;
	char	**map;
	int		line;
	int		column;
	int		player_n;
	double	player_pos_x;
	double	player_pos_y;
}	t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
	int		high;
	int		width;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*f;
	char		**f_mtx;
	char		*c;
	char		**c_mtx;
	int			x;
	int			y;
	int			ray_uncasted;
	double		ray_lenght;
	double		ray_x;
	double		ray_y;
	double		rad_p;
	double		rad_ray;
	int			newx1a;
	double		newya;
	int			newy1b;
	double		newxb;
	double		hypotena;
	double		hypotenb;
	int			map_i;
	int			map_j;
	int			x_arrow;
	int			y_arrow;
	t_img		n;
	t_img		s;
	t_img		e;
	t_img		w;
	t_vars		*vars;
	t_player	player;
}	t_game;

# define W 119
# define A 97
# define D 100
# define S 115
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define TILESIZE 128

# define CONST_RAD 0.001454441043329
# define PI 3.141592653589793

# define EST_IMG "assets/east_texture.xpm"
# define NORD_IMG "assets/north_texture.xpm"
# define SUD_IMG "assets/south_texture.xpm"
# define WEST_IMG "assets/west_texture.xpm"

/*small checks*/
void	check_path(char *path, t_game *game);
void	check_ac(int ac, t_game *game);

/*utils*/
char	*ft_itoa(int n);
char	*ft_strchr2(const char *s, int c);
long	ft_atoi(const char *str);

/*init map*/
int		init_map(char *path, t_game *game);
int		count_line(char *path);
int		count_column(char *path);

/*check_paths*/
void	check_paths(t_game *game);
void	check_no(t_game *game);
void	check_so(t_game *game);
void	check_ea(t_game *game);
void	check_we(t_game *game);

/*clean_paths*/
void	clean_paths(t_game *game);

/*check_colors*/
void	check_colors(t_game *game);
void	check_f(t_game *game);
void	check_c(t_game *game);

/*checks_errors*/
void	check_errors(t_game *game);
void	check_edges(t_game *game, int i, int j);
void	checks_vars(t_game *game);
void	error(t_game *game, int id);

/*exit_manage*/
int		close_generic(t_game *game);
void	free_vars(t_game *game);
void	free_get(void);

/*check_raycast*/
void	check_raycast(t_game *game);
void	ft_ray_in_plane(t_game *game, int i);

/*set_ray*/
double	ft_ray_on_plane(t_game *game, double hypo_lenght);
void	ft_set_ray_to_1079(t_game *game, double q, double m, int i);
void	ft_set_ray_to_2159(t_game *game, double q, double m, int i);
void	ft_set_ray_to_3239(t_game *game, double q, double m, int i);
void	ft_set_ray_after_3239(t_game *game, double q, double m, int i);

/*ray_lenght*/
double	ft_ray_lenght_to_1079(t_game *game, double q, double m);
double	ft_ray_lenght_to_2159(t_game *game, double q, double m);
double	ft_ray_lenght_to_3239(t_game *game, double q, double m);
double	ft_ray_lenght_after_3239(t_game *game, double q, double m);

/*ray_lenght_utils*/
int		ft_floor(double i);
int		control_a(t_game *game, int dir);
int		control_b(t_game *game, int dir);
void	ray_loop_a(t_game *game, double q, double m, int dir);
void	ray_loop_b(t_game *game, double q, double m, int dir);

/*ray_utils*/
void	ft_fakeray(t_game *game, int i);
int		get_pixel(t_game *game, int x, int y);
void	ft_floor_n_ceil(t_game *game, int col);
void	assets_init(t_game *game);

/*mlx utils*/
int		my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		iswhite(char c);

/*hooks*/
int		controls_working(int command, t_game *game);
int		ft_a(t_game *game);
int		ft_w(t_game *game);
int		ft_s(t_game *game);
int		ft_d(t_game *game);

/*player_utils*/
void	set_player_pos(t_game *game);
void	player_dir(t_game *game, char c);

/*ft_split*/
char	**ft_split(char const *s, char c);

/*calloc*/
void	*ft_calloc(size_t count, size_t size);

#endif
