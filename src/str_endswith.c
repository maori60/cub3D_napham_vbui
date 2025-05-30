/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_endswith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:28:43 by napham            #+#    #+#             */
/*   Updated: 2025/05/31 00:39:33 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	str_endswith(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;
	char	*str_suffix;

	str_len = 0;
	suffix_len = 0;
	while (str[str_len])
		str_len++;
	while (suffix[suffix_len])
		suffix_len++;
	if (suffix_len > str_len)
	{
		return (false);
	}
	str_suffix = (char *)str + str_len - suffix_len;
	while (*str_suffix && *suffix)
	{
		if (*str_suffix != *suffix)
			return (false);
		str_suffix++;
		suffix++;
	}
	return (*suffix == '\0');
}
