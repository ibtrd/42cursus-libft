/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:56 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/14 16:12:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_itoa_len(int n);

char	*ft_itoa(int n)
{
	char		*ptr;
	long long	n2;
	size_t		len;

	len = ft_get_itoa_len(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	n2 = (long long)n;
	if (n < 0)
		n2 *= -1;
	while (len--)
	{
		ptr[len] = n2 % 10 + '0';
		n2 /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

static size_t	ft_get_itoa_len(int n)
{
	size_t	i;

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
