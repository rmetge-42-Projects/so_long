/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:08 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/13 16:21:23 by rmetge           ###   ########.fr       */
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
	int		e;
	int		p;
	int		c;
}	t_vars;

char	**parsing(int	argc, char **argv);
void	ft_map_clear(char **map);

#endif