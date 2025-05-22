/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:53:10 by vbui              #+#    #+#             */
/*   Updated: 2025/05/21 23:10:54 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSER_H
# define FILE_PARSER_H

# include "../includes/cub3d.h"

int	trim_file_lines(char **lines);
int	parse_all_lines(char **file, t_game *data);
int	parse_and_validate_map(t_game *data, int map_start);

#endif
