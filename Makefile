.PHONY: all re clean fclean

# Nom du programme
NAME	= cub3D

# Compilateur et options
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3

# Répertoires
PARSING_PATH	= ./src/parsing/
SRC_PATH		= ./src/sources/
INIT_PATH		= ./src/init/
INC_PATH		= ./includes/
OBJ_PATH		= ./objects/

# Libft
LIBFT_PATH	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Fichiers sources
PARSING_FILES = args_checker.c \
				file_loader.c \
				texture_checker.c \
				map_validator.c \
				map_boundaries.c \
				map_loader.c \
				rgb_parser.c \
				map_validator_utils.c \
				rgb_utils.c \
				parse_texture_line.c \
				texture_utils.c  \
				find_player_position.c \
				file_parser.c \
				load_map_file.c \
				player_utils.c \
				player_position.c

SRC_FILES = main.c \
            map_utils.c \
			error_utils.c \
			free_utils.c \
			rgb_utils.c 

INIT_FILES = init_mlx.c \
			 init_texinfo.c \
             init_textures.c

# Générer les chemins complets des fichiers source
SRCS = $(addprefix $(PARSING_PATH), $(PARSING_FILES)) \
       $(addprefix $(SRC_PATH), $(SRC_FILES)) \
       $(addprefix $(INIT_PATH), $(INIT_FILES))

# Fichiers objets correspondants
OBJS = $(SRCS:%.c=$(OBJ_PATH)%.o)

# Commande principale
all: $(LIBFT) $(NAME)

# Compilation du programme principal
$(NAME): minilibx-linux/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) minilibx-linux/libmlx.a $(LIBFT) -o $(NAME) -I $(INC_PATH) -I $(LIBFT_PATH) -I $(INIT_PATH) 

# Création des fichiers objets
$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIBFT_PATH) -I $(INIT_PATH)


# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_PATH)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_PATH) minilibx-linux
	make -C $(LIBFT_PATH) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Récompilation complète
re: fclean all

# Pour debug les chemins d'objets
debug:
	@echo $(OBJS)

minilibx-linux/libmlx.a:
	rm -rf minilibx-linux && \
	curl -OL https://cdn.intra.42.fr/document/document/31613/minilibx-linux.tgz && \
	tar xf minilibx-linux.tgz && rm -rf minilibx-linux.tgz && \
	make -C minilibx-linux
