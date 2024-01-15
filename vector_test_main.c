/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:26:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 04:52:50 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int			i = 0;
	t_vector	v;
	int			*ptr;
	int			j = 125;

	ft_vector_init(&v, sizeof(int));
	while (i < 25)
	{
		ft_vector_add(&v, &i);
		i++;
	}
	i = 0;
	ft_vector_delete(&v, 2);
	ft_vector_set(&v, 5, &j);
	ptr=ft_vector_get(&v, i);
	while (i < 24)
	{
		printf("\n");
		printf("total=%zu|\n", v.total);
		printf("ptr=%p|\n", ptr);
		printf("\tv%d %d|\n", i, *ptr);
		ptr++;
		i++;
	}
	ft_vector_free(&v);
}
