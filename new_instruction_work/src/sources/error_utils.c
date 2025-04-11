/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:16:00 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 01:17:31 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int	display_error_message(char *context, char *message, int return_code)
{
	if (context)
		fprintf(stderr, "[%s] ", context);
	fprintf(stderr, "%s\n", message);
	return (return_code);
}

int	err_msg(char *detail, char *str, int code)
{
	return (display_error_message(detail, str, code));
}

int	err_msg_val(int detail, char *str, int code)
{
	char	msg[256];

	snprintf(msg, sizeof(msg), "%d: %s", detail, str);
	return (display_error_message(NULL, msg, code));
}
