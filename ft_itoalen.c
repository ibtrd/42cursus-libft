/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:05:54 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/23 02:18:13 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoalen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_itoalenbase(int n, char *base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base);
	i = 1;
	if (n < 0)
		i++;
	while (n / base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}
