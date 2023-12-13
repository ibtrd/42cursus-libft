/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:17:09 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/23 00:31:22 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *str, int fd)
{
	ssize_t	wr_str;
	ssize_t	wr_endl;

	wr_str = write(fd, str, ft_strlen(str));
	if (wr_str == -1)
		return (wr_str);
	wr_endl = write(fd, "\n", 1);
	if (wr_endl == -1)
		return (wr_endl);
	return (wr_str + wr_endl);
}
