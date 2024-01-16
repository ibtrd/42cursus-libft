/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:38:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/16 02:28:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strtol_init(const char **s, int base);
static long	strtol_accretion(const char **s, int base);

long	ft_strtol(const char *ptr, char **endptr, int base)
{
	const char		*s;
	int				sign;
	unsigned long	acc;

	s = ptr;
	sign = strtol_init(&s, base);
	acc = strtol_accretion(&s, base);
	if (endptr)
		*endptr = (char *)s;
	return (acc * sign);
}

static int	strtol_init(const char **ptr, int base)
{
	const char	*s;
	int			i;
	int			sign;

	i = 0;
	s = *ptr;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else
	{
		sign = 1;
		if (s[i] == '+')
			i++;
	}
	if (base == 16 && s[i] == '0' && s[i + 1] == 'x')
		i += 2;
	*ptr = s + i;
	return (sign);
}

#include <stdio.h>

static long	strtol_accretion(const char **s, int base)
{
	long	acc;
	char	c;

	acc = 0;
	c = *(*s++);
	while (c)
	{
		printf("c = %c\n", c);
		printf("acc = %ld\n", acc);
		if (c >= '0' && c <= '9')
			c -= '0';
		else if (c >= 'A' && c <= 'Z')
			c -= 'A' - 10;
		else if (c >= 'a' && c <= 'z')
			c -= 'z' - 10;
		else
			break ;
		printf("c = %d", (int)c);
		if (c >= base)
			break ;
		else
			acc = acc * 10 + c;
		c = *(*s++);
	}
	return (acc);
}

// static char	get_add_value(char c)
// {

// }
