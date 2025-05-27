.PHONY: all re clean fclean

NAME	= cub3D

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3

SRC_PATH		= src/
INC_PATH		= includes/
OBJ_PATH		= objects/

SRCS = main.c \
		error_utils.c \
		free_utils.c \
		keys.c \
		raycasting.c \
		render.c \
		player.c

OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) minilibx-linux/libmlx.a $(LIBFT) -lX11 -lXext -lm -o $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)


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
