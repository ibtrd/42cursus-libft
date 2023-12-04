/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:08:18 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/04 23:59:10 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*cache = NULL;
	char		*next_line;

	next_line = NULL;
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX / 2)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	cache = gnl_assembler(cache, fd);
	if (!cache)
		return (NULL);
	if (cache[0])
		next_line = gnl_trimline(cache);
	if (!next_line)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	cache = gnl_trimcache(cache);
	return (next_line);
}

void	gnl_strlcpy(char *dst, const char *src, size_t size)
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
