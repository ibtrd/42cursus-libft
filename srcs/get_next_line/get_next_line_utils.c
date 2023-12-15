/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:26:50 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/15 02:47:11 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_newline_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	gnl_len_to_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	return (i);
}

void	gnl_reinit_buffer(char	*buffer)
{
	size_t	i;
	size_t	j;

	i = gnl_len_to_newline(buffer);
	j = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[j++] = buffer[i++];
	}
}

// size_t	ft_strlen_protected(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str && str[i])
// 		i++;
// 	return (i);
// }
