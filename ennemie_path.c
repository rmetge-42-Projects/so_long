/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemie_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:24:37 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/26 17:36:03 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	good_nbr(t_vars *vars)
{
	if (vars->m[0] < vars->p[0]
		&& (vars->maps[next_p(vars->m[0])][vars->m[1]] == '0'
		|| vars->maps[next_p(vars->m[0])][vars->m[1]] == 'P'))
		moov_mw(vars);
	else if (vars->m[1] < vars->p[1]
		&& (vars->maps[vars->m[0]][next_p(vars->m[1])] == '0'
		|| vars->maps[vars->m[0]][next_p(vars->m[1])] == 'P'))
		moov_md(vars);
	else if (vars->m[0] > vars->p[0]
		&& (vars->maps[before_p(vars->m[0])][vars->m[1]] == '0'
		|| vars->maps[before_p(vars->m[0])][vars->m[1]] == 'P'))
		moov_ms(vars);
	else if (vars->m[1] > vars->p[1]
		&& (vars->maps[vars->m[0]][before_p(vars->m[1])] == '0'
		|| vars->maps[vars->m[0]][before_p(vars->m[1])] == 'P'))
		moov_ma(vars);
	else
		return (0);
	return (1);
}

int	path_m(t_vars *vars)
{
	if (good_nbr(vars) == 1)
		return (0);
	if (vars->maps[next_p(vars->m[0])][vars->m[1]] == '0'
		|| vars->maps[next_p(vars->m[0])][vars->m[1]] == 'P')
		moov_mw(vars);
	else if (vars->maps[vars->m[0]][next_p(vars->m[1])] == '0'
		|| vars->maps[vars->m[0]][next_p(vars->m[1])] == 'P')
		moov_md(vars);
	else if (vars->maps[before_p(vars->m[0])][vars->m[1]] == '0'
		|| vars->maps[before_p(vars->m[0])][vars->m[1]] == 'P')
		moov_ms(vars);
	else if (vars->maps[vars->m[0]][before_p(vars->m[1])] == '0'
		|| vars->maps[vars->m[0]][before_p(vars->m[1])] == 'P')
		moov_ma(vars);
	return (0);
}

int	m_path(t_vars *vars)
{
	path_m(vars);
	return (0);
}
