# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 15:24:26 by egiubell          #+#    #+#              #
#    Updated: 2024/06/21 05:02:38 by egiubell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

CC =		gcc -g -lm
FLAGS =		-Wall -Wextra -Werror -I./include -02
SRC_DIR =	./src
OBJ_DIR =	./obj

SRC =	$(SRC_DIR)/cub3d.c \
		$(SRC_DIR)/ft_printf/ft_printf.c \
		$(SRC_DIR)/get_next_line/get_next_line.c \
		$(SRC_DIR)/get_next_line/get_next_line_utils.c \
		$(SRC_DIR)/init_map/init_map.c \
		$(SRC_DIR)/init_map/checks_errors.c \
		$(SRC_DIR)/init_map/checks_edges.c \
		$(SRC_DIR)/init_map/player_utils.c \
		$(SRC_DIR)/init_map/check_colors.c \
		$(SRC_DIR)/init_map/check_paths.c \
		$(SRC_DIR)/init_map/clean_paths.c \
		$(SRC_DIR)/init_map/clean_colors.c \
		$(SRC_DIR)/init_map/check_paths_texture.c \
		$(SRC_DIR)/utils/utils.c \
		$(SRC_DIR)/utils/utils2.c \
		$(SRC_DIR)/utils/small_checks.c \
		$(SRC_DIR)/utils/exit_manage.c \
		$(SRC_DIR)/utils/ft_split.c \
		$(SRC_DIR)/raycast/check_raycast.c \
		$(SRC_DIR)/raycast/ray_lenght.c \
		$(SRC_DIR)/raycast/ray_lenght_utils.c \
		$(SRC_DIR)/raycast/set_ray.c \
		$(SRC_DIR)/raycast/ray_utils.c \
		$(SRC_DIR)/mlx_utils/hooks.c \
		$(SRC_DIR)/mlx_utils/mlx_utils.c \
		

RM =		rm -rf
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
NORMI = norminette
NORM_FOLDER = ./src ./include
MLX_LIBS = -L./minilibx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

all: obj_dir $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx/
	@$(CC) $(OBJ) $(CFLAGS) $(MLX_LIBS) -o $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

obj_dir:
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@$(NORMI)
	@-$(NORMI) $(NORM_FOLDER) 2>/dev/null

.PHONY: all clean fclean re norm obj_dir
