/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_multifd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:16:55 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/15 02:44:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_multifd(int fd)
{
	static t_buffer	*list = NULL;
	char			*buffer;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		list = gnl_free_all(list);
		return (NULL);
	}
	buffer = gnl_get_buffer(&list, fd);
	if (!buffer)
	{
		list = gnl_free_all(list);
		return (NULL);
	}
	next_line = build_next_line(buffer, fd);
	if (!next_line)
		gnl_free_fd(&list, fd);
	return (next_line);
}

char	*gnl_get_buffer(t_buffer **head, int fd)
{
	t_buffer	*new;
	t_buffer	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr->buffer);
		curr = curr->next;
	}
	new = malloc(sizeof(t_buffer));
	if (!new)
		return (NULL);
	new->buffer[0] = '\0';
	new->fd = fd;
	new->next = *head;
	*head = new;
	return ((*head)->buffer);
}

void	gnl_free_fd(t_buffer **head, int fd)
{
	t_buffer	*prev;
	t_buffer	*curr;
	t_buffer	*next;

	prev = NULL;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = next;
			else
				*head = next;
			free(curr);
			return ;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

t_buffer	*gnl_free_all(t_buffer *curr)
{
	t_buffer	*next;

	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	return (NULL);
}
