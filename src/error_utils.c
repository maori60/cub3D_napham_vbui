/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:16:00 by vbui              #+#    #+#             */
/*   Updated: 2025/05/29 20:22:39 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

void	err_msg(char *context, char *message)
{
	printf("Error\n");
	if (context)
		printf("[%s] ", context);
	printf("%s\n", message);
}
