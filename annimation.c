/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annimation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:01:03 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/26 17:33:14 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_a(t_vars *vars)
{
	void			*img;
	static int		i = 0;
	static size_t	x = 1;

	if (i == 4000 || x + 2 == ft_strlen(vars->maps[0]))
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_1, x * 80, 0);
		if (x + 2 == ft_strlen(vars->maps[0]))
			x = 1;
		x++;
	}
	if (i < 1000)
		img = vars->a1;
	else if (i < 2000)
		img = vars->a2;
	else if (i < 3000)
		img = vars->a4;
	else if (i < 4000)
		img = vars->a5;
	else if (i < 5000)
		img = vars->a6;
	else
		return (i = 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * 80, 0 * 80);
	return (++i);
}

void	init_img_a(t_vars *vars)
{
	int		img_w;
	int		img_h;

	vars->a1 = mlx_xpm_file_to_image(vars->mlx, "./a10.xpm", &img_w, &img_h);
	vars->a2 = mlx_xpm_file_to_image(vars->mlx, "./a2.xpm", &img_w, &img_h);
	vars->a4 = mlx_xpm_file_to_image(vars->mlx, "./a5.xpm", &img_w, &img_h);
	vars->a5 = mlx_xpm_file_to_image(vars->mlx, "./a6.xpm", &img_w, &img_h);
	vars->a6 = mlx_xpm_file_to_image(vars->mlx, "./a7.xpm", &img_w, &img_h);
}

void	destroy_img_a(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->a1);
	mlx_destroy_image(vars->mlx, vars->a2);
	mlx_destroy_image(vars->mlx, vars->a4);
	mlx_destroy_image(vars->mlx, vars->a5);
	mlx_destroy_image(vars->mlx, vars->a6);
}
