/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:08 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/15 12:29:29 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**maps;
	int		e[2];
	int		p[2];
	int		c;
}	t_vars;

int		parsing(int	argc, char **argv, t_vars *vars);
void	ft_map_clear(char **map);
int		strlen_file(char *file);
char	**use_file(char *file);
int		file_ber(char *file);
int		true_path(t_vars *vars);

#endif