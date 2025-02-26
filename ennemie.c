/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:15:14 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/26 17:33:46 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moov_mw(t_vars *vars)
{
	vars->maps[vars->m[0]][vars->m[1]] = '0';
	vars->m[0]++;
	if (vars->maps[vars->m[0]][vars->m[1]] == 'P')
		vars->m[2] = 1;
	vars->maps[vars->m[0]][vars->m[1]] = 'M';
	vars->img_m = vars->img_mw;
	return (1);
}

int	moov_ma(t_vars *vars)
{
	vars->maps[vars->m[0]][vars->m[1]] = '0';
	vars->m[1]--;
	if (vars->maps[vars->m[0]][vars->m[1]] == 'P')
		vars->m[2] = 1;
	vars->maps[vars->m[0]][vars->m[1]] = 'M';
	vars->img_m = vars->img_mg;
	return (1);
}

int	moov_ms(t_vars *vars)
{
	vars->maps[vars->m[0]][vars->m[1]] = '0';
	vars->m[0]--;
	if (vars->maps[vars->m[0]][vars->m[1]] == 'P')
		vars->m[2] = 1;
	vars->maps[vars->m[0]][vars->m[1]] = 'M';
	vars->img_m = vars->img_ma;
	return (1);
}

int	moov_md(t_vars *vars)
{
	vars->maps[vars->m[0]][vars->m[1]] = '0';
	vars->m[1]++;
	if (vars->maps[vars->m[0]][vars->m[1]] == 'P')
		vars->m[2] = 1;
	vars->maps[vars->m[0]][vars->m[1]] = 'M';
	vars->img_m = vars->img_md;
	return (1);
}
