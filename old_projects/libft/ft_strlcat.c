/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:07:50 by vbui              #+#    #+#             */
/*   Updated: 2023/11/26 22:21:26 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;
	size_t	j;

	index = ft_strlen(s);
	if (dstsize != 0)
	{
		dst_len = ft_strlen(d);
		dstsize -= 1;
		i = dst_len;
		j = 0;
		while (i < dstsize && s[j])
			d[i++] = s[j++];
		if (dstsize + 1 > dst_len)
		{
			d[i] = '\0';
			index += dst_len;
		}
		else
			index += dstsize + 1;
	}
	return (index);
}
