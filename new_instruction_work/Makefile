.PHONY: all re clean fclean

# Nom du programme
NAME	= cub3D

# Compilateur et options
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3

# Répertoires
PARSING_PATH	= ./PARSING/
SRC_PATH		= ./sources/
INIT_PATH		= ./init/
INC_PATH		= ./includes/
OBJ_PATH		= ./objects/

# Libft
LIBFT_PATH	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# MiniLibX
MLX_LIB_PATH	= ./minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_LIB_PATH)$(MLX_NAME)
MLX_FLAGS	= -L$(MLX_LIB_PATH) -lmlx -lm -lX11 -lXext -lbsd

# Fichiers sources
PARSING_FILES = args_checker.c \
				file_loader.c \
				texture_checker.c \
				map_validator.c \
				map_boundaries.c \
				map_loader.c \
				rgb_parser.c \
				player_position.c

SRC_FILES = main.c \
            map_utils.c \
			utils.c

INIT_FILES = init_mlx.c \
             init_textures.c

# Générer les chemins complets des fichiers source
SRCS = $(addprefix $(PARSING_PATH), $(PARSING_FILES)) \
       $(addprefix $(SRC_PATH), $(SRC_FILES)) \
       $(addprefix $(INIT_PATH), $(INIT_FILES))

# Fichiers objets correspondants
OBJS = $(SRCS:%.c=$(OBJ_PATH)%.o)

# Commande principale
all: $(MLX) $(LIBFT) $(NAME)

# Compilation du programme principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INC_PATH) -I $(LIBFT_PATH) -I $(INIT_PATH) -I $(MLX_LIB_PATH) $(LIBFT) $(MLX_FLAGS)

# Création des fichiers objets
$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIBFT_PATH) -I $(INIT_PATH) -I $(MLX_LIB_PATH)

# Compilation de MiniLibX
$(MLX):
	make -C $(MLX_LIB_PATH)

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_PATH)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_LIB_PATH) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_LIB_PATH) clean

# Récompilation complète
re: fclean all

debug:
	@echo $(OBJS)
