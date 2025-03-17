# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 22:12:53 by vbui              #+#    #+#              #
#    Updated: 2025/01/29 23:46:14 by vbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#						FONCTIONS DEMANDEES	        						   #
################################################################################

FILESC	= \
	ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_isspace.c

################################################################################
#						FONCTIONS ADDITIONNELLES							   #
################################################################################

FONCTADD	= \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_substr.c \

################################################################################
#						FONCTIONS BONUS										   #
################################################################################

BONUS	= \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

################################################################################
#						GET_NEXT_LINE										   #
################################################################################

GNL_FILES	= \
	get_next_line.c \
	get_next_line_utils.c \

GNL_BONUS	= \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

################################################################################
#						CONFIGURATIONS										   #
################################################################################

SRCS = ${FILESC} ${FONCTADD} ${GNL_FILES}

OBJS = ${SRCS:.c=.o}

BONUS_OBJS		= $(BONUS:.c=.o) $(GNL_BONUS:.c=.o)

CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

################################################################################
#						RÈGLES												   #
################################################################################

# Compilation de libft avec les fichiers de base et GNL
all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

# Ajoute les fichiers bonus (libft + GNL bonus)
bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Nettoyage des fichiers objets
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

# Nettoyage complet
fclean:			clean
				$(RM) $(NAME)

# Recompilation complète
re:				fclean $(NAME)

# Génération de la version dynamique (libft.so)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
