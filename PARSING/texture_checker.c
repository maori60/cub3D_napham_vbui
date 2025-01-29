/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:14 by vbui              #+#    #+#             */
/*   Updated: 2025/01/29 00:29:56 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

/**
 * Vérifie que les valeurs RGB sont dans la plage 0-255.
 */
static int validate_rgb_values(int *rgb) {
    for (int i = 0; i < 3; i++) {
        if (rgb[i] < 0 || rgb[i] > 255)
            return display_error(NULL, "Error: Invalid RGB value.", FAILURE);
    }
    return SUCCESS;
}

/**
 * Convertit un tableau RGB en une valeur hexadécimale.
 */
static unsigned long rgb_to_hex(int *rgb) {
    return ((rgb[0] & 0xFF) << 16) + ((rgb[1] & 0xFF) << 8) + (rgb[2] & 0xFF);
}

/**
 * Valide les textures et couleurs définies dans la carte.
 */
int validate_textures_and_colors(t_data *data, t_texinfo *textures) {
    if (!data || !textures)
        return display_error(NULL, "Error: Invalid data or textures.", FAILURE);

    printf("North texture: %s\n", textures->north ? textures->north : "NULL");
    printf("South texture: %s\n", textures->south ? textures->south : "NULL");
    printf("West texture: %s\n", textures->west ? textures->west : "NULL");
    printf("East texture: %s\n", textures->east ? textures->east : "NULL");

    if (!textures->north || !textures->south || !textures->west || !textures->east)
        return display_error(NULL, "Error: Missing texture path.", FAILURE);

    if (!textures->floor || !textures->ceiling)
        return display_error(NULL, "Error: Missing color definition.", FAILURE);

    if (validate_rgb_values(textures->floor) == FAILURE || validate_rgb_values(textures->ceiling) == FAILURE)
        return FAILURE;

    textures->hex_floor = rgb_to_hex(textures->floor);
    textures->hex_ceiling = rgb_to_hex(textures->ceiling);

    return SUCCESS;
}

/**
 * Parse une ligne de texte pour extraire et attribuer les textures et les couleurs.
 */
int parse_texture_line(char *line, t_data *data) {
    t_texinfo *textures = &data->texinfo;

    // Vérification pour la texture du nord
    if (ft_strncmp(line, "NO ", 3) == 0) {
        textures->north = ft_strdup(line + 3);
        if (!textures->north)
            return display_error(NULL, "Error: Memory allocation failed for NO texture.", FAILURE);
    }
    // Vérification pour la texture du sud
    else if (ft_strncmp(line, "SO ", 3) == 0) {
        textures->south = ft_strdup(line + 3);
        if (!textures->south)
            return display_error(NULL, "Error: Memory allocation failed for SO texture.", FAILURE);
    }
    // Vérification pour la texture de l'ouest
    else if (ft_strncmp(line, "WE ", 3) == 0) {
        textures->west = ft_strdup(line + 3);
        if (!textures->west)
            return display_error(NULL, "Error: Memory allocation failed for WE texture.", FAILURE);
    }
    // Vérification pour la texture de l'est
    else if (ft_strncmp(line, "EA ", 3) == 0) {
        textures->east = ft_strdup(line + 3);
        if (!textures->east)
            return display_error(NULL, "Error: Memory allocation failed for EA texture.", FAILURE);
    }
    // Vérification pour la couleur du sol
    else if (ft_strncmp(line, "F ", 2) == 0) {
        return parse_rgb_colors(&data->texinfo, line + 2, 1); // 1 pour le sol
    }
    // Vérification pour la couleur du plafond
    else if (ft_strncmp(line, "C ", 2) == 0) {
        return parse_rgb_colors(&data->texinfo, line + 2, 0); // 0 pour le plafond
    }
    
    return SUCCESS;
}
