/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:45:46 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/13 14:03:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	void	*ptr;
	int		i;
	
	i = 0;
	if (ac < 2)
	{
		ft_putendl_fd("No argument!", 1);
		return (1);
	}
	if (ac == 2)
	{
		printf("atoi=%d | ft_atoi=%d\n", atoi(av[1]), ft_atoi(av[1]));
	}
	if (ac == 3)
	{
		ptr = ft_calloc(ft_atoi(av[1]), ft_atoi(av[2]));
		printf("%p\n", ptr);
		free(ptr);
		printf("%d\n", ft_atoi(av[1]) * ft_atoi(av[2]));
		printf("%d", INT_MAX / ft_atoi(av[2]));
		// SPLIT
		char	**split;

		split = ft_split(av[1], av[2][0]);
		while (split[i])
		{
			printf("-%s", split[0]);
			i++;
		}
		free(ptr);
	}
	return (0);
}
