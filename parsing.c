/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:13:19 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/24 15:31:10 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(char **map)
{
	size_t	size;
	int		i;

	size = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (size != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (size);
}

int	chek_mur(char **map)
{
	int	i;
	int	l;

	i = 0;
	l = 1;
	while (map[0][i])
	{
		if (map[0][i++] != '1')
			return (0);
	}
	while (map[l])
	{
		if (map[l][0] != '1' || map[l][ft_strlen(map[l]) - 1] != '1')
			return (0);
		l++;
	}
	i = 0;
	l--;
	while (map[l][i])
	{
		if (map[l][i++] != '1')
			return (0);
	}
	return (1);
}

int	position(t_vars *vars, int y)
{
	int	x;

	x = 0;
	while (vars->maps[y][x])
	{
		if (vars->maps[y][x] == 'P' && vars->p[0] == -1)
		{
			vars->p[0] = y;
			vars->p[1] = x;
		}
		else if (vars->maps[y][x] == 'E' && vars->e == 0)
			vars->e = 1;
		else if (vars->maps[y][x] == 'C')
			vars->c++;
		else if (vars->maps[y][x] != '1' && vars->maps[y][x] != '0')
			return (0);
		x++;
	}
	return (1);
}

int	chek_val(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->maps[y])
	{
		if (position(vars, y) == 0)
			return (0);
		y++;
	}
	if (vars->c == 0)
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_vars *vars)
{
	if (argc != 2)
		return (ft_printf("Error\nNot the right number of arguments"), 0);
	if (file_ber(argv[1]) != 0)
		return (ft_printf("Error\nNot a .ber file"), 0);
	if (file_null(argv[1]) == 0)
		return (ft_printf("Error\nFile is null"), 0);
	vars->maps = use_file(argv[1]);
	vars->p[0] = -1;
	vars->e = 0;
	vars->c = 0;
	if (check_size(vars->maps) == 0)
		return (ft_map_clear(vars->maps), ft_printf("Error\nNot good size"), 0);
	if (chek_mur(vars->maps) == 0 || chek_val(vars) == 0)
		return (ft_map_clear(vars->maps),
			ft_printf("Error\nNot good values"), 0);
	if (true_path(vars) == 0)
		return (ft_map_clear(vars->maps),
			ft_printf("Error\nNot good path"), 0);
	ft_map_clear(vars->maps);
	vars->maps = use_file(argv[1]);
	return (1);
}
