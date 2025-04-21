/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:53:10 by vbui              #+#    #+#             */
/*   Updated: 2025/04/12 00:56:29 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSER_H
# define FILE_PARSER_H

# include "../includes/cub3d.h"

int	trim_file_lines(char **lines);
int	parse_all_lines(char **file, t_data *data);
int	parse_and_validate_map(t_data *data, int map_start);

#endif
