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

test-leaks: re
	@clear
	@echo Senza parametri
	-valgrind ./cub3D
	@echo
	@echo Piu di un parametro
	-valgrind ./cub3D maps/1.cub maps/2.cub
	@echo
	@echo Mappa inesistente
	-valgrind ./cub3D maps/no_exist.cub
	@echo
	@echo Mappa non .aanghi
	-valgrind ./cub3D maps/1.aanghi
	@echo
	@echo Manca la configurazione del soffitto
	-valgrind ./cub3D maps/error1.cub
	@echo
	@echo Manca la mappa
	-valgrind ./cub3D maps/error2.cub
	@echo
	@echo 0 player nella mappa
	-valgrind ./cub3D maps/error3.cub
	@echo
	@echo 1+ player nella mappa
	-valgrind ./cub3D maps/error4.cub
	@echo
	@echo Mappa aperta con lo 0
	-valgrind ./cub3D maps/error5.cub
	@echo
	@echo Mappa aperta con lo  
	-valgrind ./cub3D maps/error6.cub
	@echo
	@echo Spazi nella configurazione dei colori
	-valgrind ./cub3D maps/error7.cub
	@echo
	@echo Assente configurazione dei colori
	-valgrind ./cub3D maps/error8.cub
	@echo
	@echo Numero negativo nella configurazione dei colori
	-valgrind ./cub3D maps/error9.cub
	@echo
	@echo Numero oltre 255 nella configurazione dei colori
	-valgrind ./cub3D maps/error10.cub
	@echo
	@echo File vuoto
	-valgrind ./cub3D maps/error11.cub
	@echo
	@echo Assente configurazione delle texture
	-valgrind ./cub3D maps/error12.cub
	@echo
	@echo Texture inesistente
	-valgrind ./cub3D maps/error13.cub
	@echo
	@echo Riga vuota nella mappa
	-valgrind ./cub3D maps/error14.cub
	@echo
	@echo Riga vuota nel file
	-valgrind ./cub3D maps/error15.cub
	@echo
	@echo Player fuori dalla mappa
	-valgrind ./cub3D maps/error16.cub
	@echo
	@echo Mappa prima della configurazione
	-valgrind ./cub3D maps/error17.cub
	@echo
	@echo Spazi dentro la mappa
	-valgrind ./cub3D maps/error18.cub
	@echo
	@echo Carattere inaspettato
	-valgrind ./cub3D maps/error19.cub
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-nleaks: re
	@clear
	@echo Senza parametri
	-./cub3D
	@echo
	@echo Piu di un parametro
	-./cub3D maps/1.cub maps/2.cub
	@echo
	@echo Mappa inesistente
	-./cub3D maps/no_exist.cub
	@echo
	@echo Mappa non .aanghi
	-./cub3D maps/1.aanghi
	@echo
	@echo Manca la configurazione del soffitto
	-./cub3D maps/error1.cub
	@echo
	@echo Manca la mappa
	-./cub3D maps/error2.cub
	@echo
	@echo 0 player nella mappa
	-./cub3D maps/error3.cub
	@echo
	@echo 1+ player nella mappa
	-./cub3D maps/error4.cub
	@echo
	@echo Mappa aperta con lo 0
	-./cub3D maps/error5.cub
	@echo
	@echo Mappa aperta con lo  
	-./cub3D maps/error6.cub
	@echo
	@echo Spazi nella configurazione dei colori
	-./cub3D maps/error7.cub
	@echo
	@echo Assente configurazione dei colori
	-./cub3D maps/error8.cub
	@echo
	@echo Numero negativo nella configurazione dei colori
	-./cub3D maps/error9.cub
	@echo
	@echo Numero oltre 255 nella configurazione dei colori
	-./cub3D maps/error10.cub
	@echo
	@echo File vuoto
	-./cub3D maps/error11.cub
	@echo
	@echo Assente configurazione delle texture
	-./cub3D maps/error12.cub
	@echo
	@echo Texture inesistente
	-./cub3D maps/error13.cub
	@echo
	@echo Riga vuota nella mappa
	-./cub3D maps/error14.cub
	@echo
	@echo Riga vuota nel file
	-./cub3D maps/error15.cub
	@echo
	@echo Player fuori dalla mappa
	-./cub3D maps/error16.cub
	@echo
	@echo Mappa prima della configurazione
	-./cub3D maps/error17.cub
	@echo
	@echo Spazi dentro la mappa
	-./cub3D maps/error18.cub
	@echo
	@echo Carattere inaspettato
	-./cub3D maps/error19.cub
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

