/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:51:20 by vbui              #+#    #+#             */
/*   Updated: 2025/03/17 16:51:16 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

/**
 * Affiche un message d'erreur formaté.
 */
int	display_error_message(char *context, char *message, int return_code)
{
	if (context)
		fprintf(stderr, "[%s] ", context);
	fprintf(stderr, "%s\n", message);
	return (return_code);
}

/**
 * Gestion d'erreur avec un message détaillé.
 */
int	err_msg(char *detail, char *str, int code)
{
	return (display_error_message(detail, str, code));
}

/**
 * Gestion d'erreur avec affichage d'une valeur associée.
 */
int	err_msg_val(int detail, char *str, int code)
{
	char	msg[256];

	snprintf(msg, sizeof(msg), "%d: %s", detail, str);
	return (display_error_message(NULL, msg, code));
}

/**
 * Libère toutes les données de `t_data`.
 */
void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->mapinfo.file)
	{
		i = 0;
		while (data->mapinfo.file[i])
		{
			free(data->mapinfo.file[i]);
			data->mapinfo.file[i] = NULL;
			i++;
		}
		free(data->mapinfo.file);
		data->mapinfo.file = NULL;
	}
	if (data->mapinfo.map)
	{
		i = 0;
		while (data->mapinfo.map[i])
		{
			free(data->mapinfo.map[i]);
			data->mapinfo.map[i] = NULL;
			i++;
		}
		free(data->mapinfo.map);
		data->mapinfo.map = NULL;
	}
	if (data->texinfo.north)
	{
		free(data->texinfo.north);
		data->texinfo.north = NULL;
	}
	if (data->texinfo.south)
	{
		free(data->texinfo.south);
		data->texinfo.south = NULL;
	}
	if (data->texinfo.west)
	{
		free(data->texinfo.west);
		data->texinfo.west = NULL;
	}
	if (data->texinfo.east)
	{
		free(data->texinfo.east);
		data->texinfo.east = NULL;
	}
	if (data->texinfo.floor)
	{
		free(data->texinfo.floor);
		data->texinfo.floor = NULL;
	}
	if (data->texinfo.ceiling)
	{
		free(data->texinfo.ceiling);
		data->texinfo.ceiling = NULL;
	}
}

/**
 * Convertit un tableau RGB en hexadécimal.
 */
// unsigned long	rgb_to_hex(int *rgb)
unsigned int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}