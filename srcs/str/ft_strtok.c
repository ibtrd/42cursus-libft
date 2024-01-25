/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 03:01:36 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/25 03:36:15 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strtok(char *s, const char *delimiters)
{
	static char	*last = NULL;
	char		c;
	char		*tok;

	if (!s)
		s = last;
	if (!s)
		return (NULL);
	c = *s++;
	while (ft_ischarset(c, delimiters))
		c = *s++;
	if (!c)
	{
		last = NULL;
		return (NULL);
	}
	tok = s - 1;
	while (c && !ft_ischarset(c, delimiters))
		c = *s++;
	if (!c)
		s = NULL;
	else
		s[-1] = '\0';
	last = s;
	return (tok);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	char	*s;
// 	int 	i;

// 	s = strtok(av[1], " ");
// 	while (s)
// 	{
// 		printf("strtok%d=%s|\n", i++, s);
// 		s = strtok(NULL, " ");
// 	}
// 	s = strtok(av[2], " ");
// 	while (s)
// 	{
// 		printf("strtok%d=%s|\n", i++, s);
// 		s = strtok(NULL, " ");
// 	}
// }
