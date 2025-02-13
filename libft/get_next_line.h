/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmetge <rmetge@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:42:53 by rmetge            #+#    #+#             */
/*   Updated: 2025/02/12 12:47:36 by rmetge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*read_stash(int fd, char *stash);
char	*ft_strjoing(char *s1, char *s2);
void	ft_bezerog(char *str, size_t n);
char	*ft_line(char *stash);
char	*ft_after(char *stash);
void	*ft_callocg(size_t nmbr, size_t size);
int		ft_strchrg(char *str, char c);
int		ft_strleng(char *str);

#endif