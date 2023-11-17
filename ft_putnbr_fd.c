/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:06:09 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/17 23:20:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd(ln % 10 + '0', fd);
}
