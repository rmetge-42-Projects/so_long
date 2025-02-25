/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:55:45 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/25 16:46:06 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moov_w(t_vars *vars)
{
	if (vars->maps[before_p(vars->p[0])][vars->p[1]] == 'C'
		|| vars->maps[before_p(vars->p[0])][vars->p[1]] == '0')
	{
		if (vars->maps[before_p(vars->p[0])][vars->p[1]] == 'C')
			vars->c-= 1;
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[0] = before_p(vars->p[0]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->cont++;
		//return (1);
	}
	else if (vars->maps[before_p(vars->p[0])][vars->p[1]] == 'M')
		vars->e = 0;
	else if (vars->maps[before_p(vars->p[0])][vars->p[1]] == 'E' && vars->c == 0)
	{
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[1] = next_p(vars->p[1]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->e = 0;
	}
	print_map(vars, vars->img_s);
	return (0);
}

int	moov_a(t_vars *vars)
{
	if (vars->maps[vars->p[0]][before_p(vars->p[1])] == '0'
		|| vars->maps[vars->p[0]][before_p(vars->p[1])] == 'C')
	{
		if (vars->maps[vars->p[0]][before_p(vars->p[1])] == 'C')
			vars->c-= 1;
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[1] = before_p(vars->p[1]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->cont++;
		//return (1);
	}
	else if (vars->maps[vars->p[0]][before_p(vars->p[1])] == 'M')
		vars->e = 0;
	else if (vars->maps[vars->p[0]][before_p(vars->p[1])] == 'E' && vars->c == 0)
	{
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[1] = next_p(vars->p[1]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->e = 0;
	}
	print_map(vars, vars->img_a);
	return (0);
}

int	moov_s(t_vars *vars)
{
	if (vars->maps[next_p(vars->p[0])][vars->p[1]] == '0'
		|| vars->maps[next_p(vars->p[0])][vars->p[1]] == 'C')
	{
		if (vars->maps[next_p(vars->p[0])][vars->p[1]] == 'C')
			vars->c-= 1;
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[0] = next_p(vars->p[0]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->cont++;
		//return (1);
	}
	else if (vars->maps[next_p(vars->p[0])][vars->p[1]] == 'M')
		vars->e = 0;
	else if (vars->maps[next_p(vars->p[0])][vars->p[1]] == 'E' && vars->c == 0)
	{
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[1] = next_p(vars->p[1]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->e = 0;
	}
	print_map(vars, vars->img_w);
	return (0);
}

int	moov_d(t_vars *vars)
{
	if (vars->maps[vars->p[0]][next_p(vars->p[1])] == '0'
		|| vars->maps[vars->p[0]][next_p(vars->p[1])] == 'C')
	{
		if (vars->maps[vars->p[0]][next_p(vars->p[1])] == 'C')
			vars->c-= 1;
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[1] = next_p(vars->p[1]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->cont++;
		//return (1);
	}
	else if (vars->maps[vars->p[0]][next_p(vars->p[1])] == 'M')
		vars->e = 0;
	else if (vars->maps[vars->p[0]][next_p(vars->p[1])] == 'E' && vars->c == 0)
	{
		vars->maps[vars->p[0]][vars->p[1]] = '0';
		vars->p[1] = next_p(vars->p[1]);
		vars->maps[vars->p[0]][vars->p[1]] = 'P';
		vars->e = 0;
	}
	print_map(vars, vars->img_d);
	return (0);
}

