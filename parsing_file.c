/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:40:31 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/15 13:45:48 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_file(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**use_file(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map = malloc((strlen_file(file) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (line)
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	return(map[i] = NULL, close(fd), map);
}

int	file_ber(char *file)
{
	int	i;

	i = (ft_strlen(file) - 4);
	return (ft_strncmp((file + i), ".ber", 4));
}

int	next_pos(int x)
{
	x++;
	return(x);
}

//tout pas bo tout moche bouuuuh
int	path_1(t_vars *vars, int y, int x)
{
	// while (vars->maps[y][x] != 'P')
	// {
		// ft_printf("y = %i\n", y);
		// ft_printf("%i\n", next_pos(y));
		while (vars->maps[next_pos(y)][x] == '0')
			y++;
		// else if (vars->maps[y][next_pos(x)] == '0')
		// 	x++;
		if (vars->maps[next_pos(y)][x] == 'C' || vars->maps[y][next_pos(x)] == 'C')
		{
			vars->c--;
			return (1);
		}
	// }
	return (0);
}

int	true_path(t_vars *vars)
{
	int	y;
	int	x;

	y = (vars->p[0]);
	x = vars->p[1];
	while (vars->c > 0)
	{
		//ft_printf("%c\n", vars->maps[y][x]);
		path_1(vars, y, x);

	}
	return (1);
}
