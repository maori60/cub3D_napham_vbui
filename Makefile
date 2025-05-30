.PHONY: all re clean fclean

NAME	= cub3D

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 # -fsanitize=address

SRC_PATH		= src/
OBJ_PATH		= objects/

SRCS = main.c init_game.c str_endswith.c \
		error_utils.c \
		keys.c \
		raycasting.c raycasting_p2.c \
		render.c render_p2.c \
		player.c \
		map/border_checking.c  map/cell_validation.c  map/element_utils.c \
		map/file_utils.c  map/map_loading.c  map/map_processing.c  map/map_utils.c  map/string_utils.c

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): minilibx-linux/libmlx.a  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) minilibx-linux/libmlx.a $(LIBFT) -lX11 -lXext -lm -o $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)/map

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_PATH) minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	@echo $(OBJS)

minilibx-linux/libmlx.a:
	rm -rf minilibx-linux && \
	curl -OL https://cdn.intra.42.fr/document/document/31613/minilibx-linux.tgz && \
	tar xf minilibx-linux.tgz && rm -rf minilibx-linux.tgz && \
	make -C minilibx-linux
