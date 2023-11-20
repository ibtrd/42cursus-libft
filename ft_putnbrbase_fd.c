/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:02:11 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/20 10:40:45 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase_fd(int n, char *base, int fd)
{
	long	ln;
	int		base_len;

	ln = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	base_len = ft_strlen(base);
	if (ln >= base_len)
		ft_putnbrbase_fd(ln / base_len, base, fd);
	ft_putchar_fd(base[ln % base_len], fd);
}
