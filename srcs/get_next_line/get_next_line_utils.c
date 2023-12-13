/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:26:50 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/13 17:39:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_assembler(char *cache, int fd)
{
	char	*buffer;
	ssize_t	rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(cache);
		return (NULL);
	}
	rd = BUFFER_SIZE;
	while (!cache || (rd > 0 && !gnl_newlinecheck(cache)))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(cache);
			cache = NULL;
			break ;
		}
		cache = gnl_joincache(cache, buffer, rd);
		if (!cache)
			break ;
	}
	free(buffer);
	return (cache);
}

char	*gnl_joincache(char *cache, char *buffer, ssize_t rd)
{
	char	*new_cache;
	size_t	len;

	buffer[rd] = '\0';
	len = ft_strlen_protected(cache);
	new_cache = NULL;
	if (len < INT_MAX / 2)
		new_cache = malloc((len + rd + 1) * sizeof(char));
	if (new_cache)
	{
		gnl_strlcpy(new_cache, cache, len + 1);
		gnl_strlcpy(new_cache + len, buffer, rd + 1);
	}
	free(cache);
	cache = NULL;
	return (new_cache);
}

char	*gnl_trimline(char *cache)
{
	char	*next_line;
	size_t	len;

	len = 0;
	while (cache[len] && cache[len] != '\n')
		len++;
	if (cache[len] == '\n')
		len++;
	next_line = malloc((len + 1) * sizeof(char));
	if (next_line)
		gnl_strlcpy(next_line, cache, len + 1);
	return (next_line);
}

char	*gnl_trimcache(char *cache)
{
	char	*new_cache;
	size_t	len;
	size_t	i;

	new_cache = NULL;
	if (!cache)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (cache[i] == '\n')
	{
		i++;
		len = 0;
		while (cache[i + len])
			len++;
		new_cache = malloc((len + 1) * sizeof(char));
		if (new_cache)
			gnl_strlcpy(new_cache, cache + i, len + 1);
	}
	free(cache);
	cache = NULL;
	return (new_cache);
}
