/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:55:27 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/28 13:14:41 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_vars *vars, int i, int j, void *img_d)
{
	void	*img;

	if (vars->maps[i][j] == '1')
		img = vars->img_1;
	else if (vars->maps[i][j] == '0')
		img = vars->img_0;
	else if (vars->maps[i][j] == 'E')
		img = vars->img_e;
	else if (vars->maps[i][j] == 'C')
		img = vars->img_c;
	else if (vars->maps[i][j] == 'M')
		img = vars->img_m;
	else
		img = img_d;
	mlx_put_image_to_window(vars->mlx, vars->win, img, j * 80, i * 80);
}

void	print_map(t_vars *vars, void *img_d)
{
	int	i;
	int	j;

	i = 0;
	if (vars->m[0] != -1)
		m_path(vars);
	while (vars->maps[i])
	{
		j = 0;
		while (vars->maps[i][j])
		{
			print_img(vars, i, j, img_d);
			j++;
		}
		i++;
	}
	img_cont(vars);
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
	if (keycode == 119 || keycode == 65362)
		moov_w(vars);
	if (keycode == 97 || keycode == 65361)
		moov_a(vars);
	if (keycode == 115 || keycode == 65364)
		moov_s(vars);
	if (keycode == 100 || keycode == 65363)
		moov_d(vars);
	if (vars->c == 0 && vars->e == 0)
		return (mlx_loop_end(vars->mlx), 1);
	if (vars->m[2] == 1)
	{
		ft_printf("looser\n");
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (parsing(argc, argv, &vars) == 0)
		return (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_strlen(vars.maps[0]) * 80,
			strlen_file(argv[1]) * 80, "So_long");
	init_img(&vars);
	init_img_a(&vars);
	vars.m[2] = 0;
	vars.img_m = vars.img_mw;
	vars.cont = 0;
	print_map(&vars, vars.img_w);
	mlx_hook(vars.win, 17, (1L << 17), mlx_loop_end, vars.mlx);
	mlx_hook(vars.win, 2, (1L << 0), keypress, &vars);
	mlx_loop_hook(vars.mlx, print_a, &vars);
	mlx_loop(vars.mlx);
	destroy_img(&vars);
	destroy_img_a(&vars);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	ft_map_clear(vars.maps);
	free(vars.mlx);
}
