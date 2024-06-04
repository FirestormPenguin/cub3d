# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 15:24:26 by egiubell          #+#    #+#              #
#    Updated: 2024/06/04 02:45:59 by egiubell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3d

CC =		gcc -g
FLAGS =		-Wall -Wextra -Werror -I./include -o
SRC_DIR =	./src
OBJ_DIR =	./obj

SRC =	$(SRC_DIR)/cub3d.c \
		$(SRC_DIR)/ft_printf/ft_printf.c \
		$(SRC_DIR)/get_next_line/get_next_line.c \
		$(SRC_DIR)/get_next_line/get_next_line_utils.c \
		$(SRC_DIR)/init_map/init_map.c \
		$(SRC_DIR)/init_map/checks_errors.c \
		$(SRC_DIR)/init_map/checks_edges.c \
		$(SRC_DIR)/utils/utils.c \
		$(SRC_DIR)/utils/small_checks.c \
		$(SRC_DIR)/utils/exit_manage.c \
		$(SRC_DIR)/init_game/init_game.c \
		$(SRC_DIR)/init_game/init_player.c \

RM =		rm -rf
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
NORMI = norminette
NORM_FOLDER = ./src ./include

all: obj_dir $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS)  -o $(NAME)


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
