/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:54:08 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/17 18:51:45 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**maps;
	int		e;
	int		p[2];
	int		c;
}	t_vars;

int		parsing(int argc, char **argv, t_vars *vars);
void	ft_map_clear(char **map);
int		strlen_file(char *file);
char	**use_file(char *file);
int		file_ber(char *file);
int		true_path(t_vars *vars);
int		file_null(char *file);
int		moov_w(t_vars *vars);
int		moov_a(t_vars *vars);
int		moov_s(t_vars *vars);
int		moov_d(t_vars *vars);
int		next_p(int p);
int		before_p(int p);

#endif