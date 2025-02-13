/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:13:19 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/13 16:34:48 by rmetge           ###   ########.fr       */
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

int	check_size(char **map)
{
	size_t	size;
	int	i;

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
			return(0);
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



int	chek_val(char **map)
{
	int	x;
	int	y;
	int	p;
	int	e;
	int	c;

	y = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' && p == 0)
				p = 1;
			else if (map[y][x] == 'E' && e == 0)
				e = 1;
			else if (map[y][x] == 'C')
				c++;
			else if (map[y][x] != '1' && map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	if (c == 0)
		return (0);
	return (1);
}

char	**parsing(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (NULL);
	if (access(argv[1], R_OK) == -1)
		return (NULL);
	map = use_file(argv[1]);
	if (check_size(map) == 0)
		return (ft_map_clear(map), NULL);
	if (chek_mur(map) == 0)
		return (ft_map_clear(map), NULL);
	if (chek_val(map) == 0)
		return (ft_map_clear(map), NULL);
	return (map);
}