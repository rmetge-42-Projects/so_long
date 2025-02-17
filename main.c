/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:55:27 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/17 13:35:39 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i = 0;

	while (map[i])
		ft_printf("%s\n", map[i++]);
}

void	ft_map_clear(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (parsing(argc, argv, &vars) == 0)
		return (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	print_map(vars.maps);
	mlx_hook(vars.win, 17, (1L << 17), mlx_loop_end, vars.mlx);
	mlx_hook(vars.win, 2, (1L << 0), keypress, &vars);

	
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	ft_map_clear(vars.maps);
	free(vars.mlx);
}
