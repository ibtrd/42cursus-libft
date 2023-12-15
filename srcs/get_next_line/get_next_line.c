/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:08:18 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/15 02:46:30 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (build_next_line(buffer, fd));
}

char	*build_next_line(char *buffer, int fd)
{
	char		*next_line;

	next_line = NULL;
	if (buffer[0])
	{
		next_line = gnl_join(NULL, buffer);
		if (!next_line)
			return (NULL);
	}
	next_line = gnl_assembler(next_line, buffer, fd);
	if (!next_line || !next_line[0])
	{
		free(next_line);
		next_line = NULL;
	}
	gnl_reinit_buffer(buffer);
	return (next_line);
}

char	*gnl_assembler(char *next_line, char *buffer, int fd)
{
	ssize_t	rd;

	rd = BUFFER_SIZE;
	while (rd != 0 && !gnl_newline_check(buffer))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(next_line);
			next_line = NULL;
			break ;
		}
		buffer[rd] = '\0';
		next_line = gnl_join(next_line, buffer);
		if (!next_line)
			break ;
	}
	return (next_line);
}

char	*gnl_join(char *prev_str, char *buffer)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = gnl_len_to_newline(buffer);
	len += ft_strlen_protected(prev_str);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str)
	{
		i = 0;
		while (prev_str && prev_str[i])
		{
			new_str[i] = prev_str[i];
			i++;
		}
		j = 0;
		while (i + j++ < len)
			new_str[i + j - 1] = buffer[j - 1];
		new_str[len] = '\0';
	}
	free(prev_str);
	return (new_str);
}
