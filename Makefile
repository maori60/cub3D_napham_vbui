.PHONY: all re clean fclean

# Nom du programme
NAME	= cub3D

# Compilateur et options
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3

# Répertoires
PARSING_PATH	= ./PARSING/
SRC_PATH		= ./sources/
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
				player_position.c

SRC_FILES = main.c \
            map_utils.c \
			utils.c

SRCS = $(addprefix $(PARSING_PATH), $(PARSING_FILES)) \
       $(addprefix $(SRC_PATH), $(SRC_FILES))

# Fichiers objets
OBJS = $(SRCS:%.c=$(OBJ_PATH)%.o)

# Commande principale
all: $(LIBFT) $(NAME)

# Compilation du programme principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INC_PATH) -I $(LIBFT_PATH) $(LIBFT)

# Création des fichiers objets
$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIBFT_PATH)

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_PATH)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Récompilation complète
re: fclean all

debug:
	@echo $(OBJS)

