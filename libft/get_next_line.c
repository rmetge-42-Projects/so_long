/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:43:54 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/12 12:51:35 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_and_free(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoing(str1, str2);
	free(str1);
	return (temp);
}

char	*ft_after(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		return (free(stash), NULL);
	}
	tmp = (char *)ft_callocg((ft_strleng(stash) - i + 1), sizeof(char));
	i++;
	while (stash[j + i])
	{
		tmp[j] = stash[j + i];
		j++;
	}
	tmp[j] = 0;
	free(stash);
	return (tmp);
}

char	*ft_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = (char *)ft_callocg((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	int		r;

	if (!stash)
		stash = (char *)ft_callocg(1, 1);
	buffer = (char *)ft_callocg(BUFFER_SIZE, sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (free(stash), free(buffer), NULL);
		buffer[r] = 0;
		stash = join_and_free(stash, buffer);
		if (ft_strchrg(buffer, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (free(stash[fd]), NULL);
	line = ft_line(stash[fd]);
	stash[fd] = ft_after(stash[fd]);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include "get_next_line.h"

// int main()
// {
// 	int fd;
// 	char *line;

// 	// Test 1: Lire un fichier texte normal
// 	printf("Test 1: Lecture d'un fichier texte\n");
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Erreur d'ouverture de fichier");
// 		return 1;
// 	}

// 	// for (int i = 0; i < 2; i++)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("ligne lu: %s", line);
// 	// }
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Ligne lue: %s            |", line);
// 		free(line);  // Libérer la mémoire allouée pour la ligne lue
// 	}
// 	close(fd);
// 	printf("Fin du test 1\n\n");
// }