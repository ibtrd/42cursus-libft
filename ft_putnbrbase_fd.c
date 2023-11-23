/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:02:11 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/23 02:18:31 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbrbase_fd(int n, char *base, int fd)
{
	ssize_t	wr;
	long	ln;
	int		base_len;

	ln = n;
	wr = 0;
	if (n < 0)
	{
		wr = ft_putchar_fd('-', fd);
		if (wr == -1)
			return (-1);
		ln *= -1;
	}
	base_len = ft_strlen(base);
	if (ln >= base_len)
		ft_putnbrbase_fd(ln / base_len, base, fd);
	wr = ft_putchar_fd(base[ln % base_len], fd);
	if (wr == -1)
		return (-1);
	return (ft_itoalenbase(n, base));
}
