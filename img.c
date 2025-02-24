/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:55:57 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/24 14:56:20 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}