/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:40:31 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/24 15:32:13 by rmetge           ###   ########.fr       */
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
	if (fd == -1)
		return (NULL);
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
	return (map[i] = NULL, close(fd), map);
}

int	file_ber(char *file)
{
	int	i;

	i = (ft_strlen(file) - 4);
	return (ft_strncmp((file + i), ".ber", 4));
}

int	file_null(char *file)
{
	int		fd;
	char	buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read(fd, &buffer, 1) == 0)
		return (0);
	return (1);
}
