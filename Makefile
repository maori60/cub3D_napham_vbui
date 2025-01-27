.PHONY: all re clean fclean

# Nom du programme
NAME	= cub3D

# Compilateur et options
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3

# Répertoires
SRC_PATH	= ./PARSING/
INC_PATH	= ./includes/
OBJ_PATH	= ./objects/

# Fichiers sources
SRC_FILES	= args_checker.c \
			  file_loader.c \
			  texture_checker.c \
			  map_validator.c \
			  map_boundaries.c \
			  map_loader.c \
			  rgb_parser.c \
			  player_position.c \
			  main.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC_FILES))

# Fichiers objets
OBJS		= $(SRCS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

# Commande principale
all: $(NAME)

# Compilation du programme principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INC_PATH)

# Création des fichiers objets
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_PATH)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Récompilation complète
re: fclean all
