/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:08:18 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/21 21:22:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*cache[MAX_FD];
	char		*next_line;

	next_line = NULL;
	if (fd == -2)
	{
		gnl_freeallcache(cache);
		return (NULL);
	}
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	cache[fd] = gnl_assembler(cache[fd], fd);
	if (!cache[fd])
		return (NULL);
	if (cache[fd][0])
		next_line = gnl_trimline(cache[fd]);
	if (!next_line)
	{
		free(cache[fd]);
		cache[fd] = NULL;
		return (NULL);
	}
	cache[fd] = gnl_trimcache(cache[fd]);
	return (next_line);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (src && src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	gnl_newlinecheck(char *cache)
{
	size_t	i;

	i = 0;
	while (cache && cache[i])
	{
		if (cache[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	gnl_freeallcache(char **cache_array)
{
	int	i;

	i = 0;
	while (i < MAX_FD)
	{
		free(cache_array[i]);
		cache_array[i] = NULL;
		i++;
	}
}
