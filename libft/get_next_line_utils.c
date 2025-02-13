/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:43:48 by rmetge            #+#    #+#             */
/*   Updated: 2025/01/25 18:02:53 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoing(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	j = 0;
	i = ft_strleng(s1) + ft_strleng(s2);
	dest = malloc(i +1 * sizeof(char));
	i = 0;
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_bezerog(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_callocg(size_t nmbr, size_t size)
{
	void	*dest;

	if (size != 0 && nmbr * size / size != nmbr)
		return (NULL);
	dest = (void *)malloc(nmbr * size);
	if (!dest)
		return (NULL);
	ft_bezerog(dest, nmbr * size);
	return (dest);
}

int	ft_strchrg(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strleng(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
