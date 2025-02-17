/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:24:36 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/17 19:00:03 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_p(int p)
{
	p++;
	return (p);
}

int	before_p(int p)
{
	if (p > 0)
		p--;
	return (p);
}

// void	print_map1(char **map)
// {
// 	int	i = 0;

// 	while (map[i])
// 		ft_printf("%s\n", map[i++]);
// }

int	path_1(t_vars *vars, int y, int x)
{
	int	c;

	c = 0;
	if (vars->maps[y][x] == 'C' || vars->maps[y][x] == 'E')
		c++;
	if (vars->maps[y][x] == 'E')
		return (vars->maps[y][x] = 'x', c);
	vars->maps[y][x] = 'x';
	if (vars->maps[next_p(y)][x] == '0' || vars->maps[next_p(y)][x] == 'C'
		|| vars->maps[next_p(y)][x] == 'E')
		c += path_1(vars, (y + 1), x);
	if (vars->maps[before_p(y)][x] == '0' || vars->maps[before_p(y)][x] == 'C'
		|| vars->maps[before_p(y)][x] == 'E')
		c += path_1(vars, (y - 1), x);
	if (vars->maps[y][next_p(x)] == '0' || vars->maps[y][next_p(x)] == 'C'
		|| vars->maps[y][next_p(x)] == 'E')
		c += path_1(vars, y, (x + 1));
	if (vars->maps[y][before_p(x)] == '0' || vars->maps[y][before_p(x)] == 'C'
		|| vars->maps[y][before_p(x)] == 'E')
		c += path_1(vars, y, (x - 1));
	//print_map1(vars->maps);
	return (c);
}

int	true_path(t_vars *vars)
{
	int	y;
	int	x;

	y = (vars->p[0]);
	x = vars->p[1];
	if ((vars->c + 1) == path_1(vars, y, x))
	{
		return (1);
	}
	return (0);
}
