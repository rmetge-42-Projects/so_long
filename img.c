/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:55:57 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/26 13:58:14 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(int c, t_vars *vars, int x)
{
	if (c == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c1, x * 80, 0);
	else if (c == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c2, x * 80, 0);
	else if (c == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c3, x * 80, 0);
	else if (c == 4)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c4, x * 80, 0);
	else if (c == 5)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c5, x * 80, 0);
	else if (c == 6)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c6, x * 80, 0);
	else if (c == 7)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c7, x * 80, 0);
	else if (c == 8)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c8, x * 80, 0);
	else if (c == 9)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c9, x * 80, 0);
	else if (c == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c0, x * 80, 0);
}

void	img_cont(t_vars *vars)
{
	int	x;
	int	c;

	c = vars->cont;
	x = 0;
	while (c > 9)
	{
		c = c / 10;
		x++;
	}
	c = vars->cont;
	while (c > 9)
	{
		ft_put((c % 10), vars, x);
		c = c / 10;
		x--;
	}
	if (c >= 0 && c <= 9)
		ft_put(c, vars, x);
}

void	init_img(t_vars *vars)
{
	int		img_w;
	int		img_h;

	vars->img_1 = mlx_xpm_file_to_image(vars->mlx, "./1.xpm", &img_w, &img_h);
	vars->img_0 = mlx_xpm_file_to_image(vars->mlx, "./0.xpm", &img_w, &img_h);
	vars->img_e = mlx_xpm_file_to_image(vars->mlx, "./e.xpm", &img_w, &img_h);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx, "./c.xpm", &img_w, &img_h);
	vars->img_w = mlx_xpm_file_to_image(vars->mlx, "./dev.xpm", &img_w, &img_h);
	vars->img_s = mlx_xpm_file_to_image(vars->mlx, "./der.xpm", &img_w, &img_h);
	vars->img_a = mlx_xpm_file_to_image(vars->mlx, "./gau.xpm", &img_w, &img_h);
	vars->img_d = mlx_xpm_file_to_image(vars->mlx, "./dro.xpm", &img_w, &img_h);
	vars->img_mw = mlx_xpm_file_to_image(vars->mlx, "./m.xpm", &img_w, &img_h);
	vars->img_md = mlx_xpm_file_to_image(vars->mlx, "./md.xpm", &img_w, &img_h);
	vars->img_ma = mlx_xpm_file_to_image(vars->mlx, "./ma.xpm", &img_w, &img_h);
	vars->img_mg = mlx_xpm_file_to_image(vars->mlx, "./mg.xpm", &img_w, &img_h);
	vars->img_c1 = mlx_xpm_file_to_image(vars->mlx, "./c1.xpm", &img_w, &img_h);
	vars->img_c2 = mlx_xpm_file_to_image(vars->mlx, "./c2.xpm", &img_w, &img_h);
	vars->img_c3 = mlx_xpm_file_to_image(vars->mlx, "./c3.xpm", &img_w, &img_h);
	vars->img_c4 = mlx_xpm_file_to_image(vars->mlx, "./c4.xpm", &img_w, &img_h);
	vars->img_c5 = mlx_xpm_file_to_image(vars->mlx, "./c5.xpm", &img_w, &img_h);
	vars->img_c6 = mlx_xpm_file_to_image(vars->mlx, "./c6.xpm", &img_w, &img_h);
	vars->img_c7 = mlx_xpm_file_to_image(vars->mlx, "./c7.xpm", &img_w, &img_h);
	vars->img_c8 = mlx_xpm_file_to_image(vars->mlx, "./c8.xpm", &img_w, &img_h);
	vars->img_c9 = mlx_xpm_file_to_image(vars->mlx, "./c9.xpm", &img_w, &img_h);
	vars->img_c0 = mlx_xpm_file_to_image(vars->mlx, "./c0.xpm", &img_w, &img_h);
}

void	destroy_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_0);
	mlx_destroy_image(vars->mlx, vars->img_1);
	mlx_destroy_image(vars->mlx, vars->img_e);
	mlx_destroy_image(vars->mlx, vars->img_c);
	mlx_destroy_image(vars->mlx, vars->img_d);
	mlx_destroy_image(vars->mlx, vars->img_w);
	mlx_destroy_image(vars->mlx, vars->img_a);
	mlx_destroy_image(vars->mlx, vars->img_s);
	mlx_destroy_image(vars->mlx, vars->img_mw);
	mlx_destroy_image(vars->mlx, vars->img_md);
	mlx_destroy_image(vars->mlx, vars->img_ma);
	mlx_destroy_image(vars->mlx, vars->img_mg);
	mlx_destroy_image(vars->mlx, vars->img_c1);
	mlx_destroy_image(vars->mlx, vars->img_c2);
	mlx_destroy_image(vars->mlx, vars->img_c3);
	mlx_destroy_image(vars->mlx, vars->img_c4);
	mlx_destroy_image(vars->mlx, vars->img_c5);
	mlx_destroy_image(vars->mlx, vars->img_c6);
	mlx_destroy_image(vars->mlx, vars->img_c7);
	mlx_destroy_image(vars->mlx, vars->img_c8);
	mlx_destroy_image(vars->mlx, vars->img_c9);
	mlx_destroy_image(vars->mlx, vars->img_c0);
}
