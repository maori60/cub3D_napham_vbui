/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:08:50 by napham            #+#    #+#             */
/*   Updated: 2025/05/29 21:00:21 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../../includes/cub3d.h"

int		ft_strlen(char *s);
char	*ft_strdup(char *s);
int		ft_atoi(char *s);
void	free_map(t_map *m);
char	*alloc_line(int size);
char	*add_char(char *line, char c, int pos);
char	*read_line(int fd);
int		get_color_val(char *s, int *i);
int		parse_rgb(char *s);
char	*trim_path(char *s);
int		set_texture(t_map *m, char *line, int i);
int		parse_elem(t_map *m, char *line);
int		is_map_char(char c);
int		is_map_line(char *line);
int		process_line(t_map *m, char *line, int *count);
int		count_map_lines(int fd, t_map *m);
int		store_map_line(t_map *m, char *line, int i);
int		process_map_line(t_map *m, char *line, int *i);
int		load_map_content(t_map *m, int fd);
int		check_first_last_row(char c);
int		check_row_overflow(t_map *m, int i, int j);
int		check_borders(t_map *m, int i, int j, int r_start);
int		get_adj_char(t_map *m, int ni, int nj);
int		check_adjacent(t_map *m, int i, int j, int di_dj);
int		check_space(t_map *m, int i, int j);
int		set_player(t_map *m, char c, int i, int j);
int		validate_cell(t_map *m, int i, int j, int r_start);
int		check_elements(t_map *m);
int		validate_row(t_map *m, int i);
int		validate_map(t_map *m);
t_map	*init_map(void);
int		get_map_height(char *path, t_map *m);
int		allocate_map(t_map *m);
void	reset_map_data(t_map *m);
int		load_and_validate(t_map *m, char *path);
t_map	*load_map(char *path);

#endif
