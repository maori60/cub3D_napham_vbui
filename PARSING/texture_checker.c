/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:01:14 by vbui              #+#    #+#             */
/*   Updated: 2025/01/28 17:28:38 by vbui             ###   ########.fr       */
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

    // Vérification des chemins de textures
    if (!textures->north || !textures->south || !textures->west || !textures->east)
        return display_error(NULL, "Error: Missing texture path.", FAILURE);

    // Vérification des couleurs
    if (!textures->floor || !textures->ceiling)
        return display_error(NULL, "Error: Missing color definition.", FAILURE);

    // Validation des valeurs RGB
    if (validate_rgb_values(textures->floor) == FAILURE || validate_rgb_values(textures->ceiling) == FAILURE)
        return FAILURE;

    // Conversion des couleurs en hexadécimal
    textures->hex_floor = rgb_to_hex(textures->floor);
    textures->hex_ceiling = rgb_to_hex(textures->ceiling);

    return SUCCESS;
}
