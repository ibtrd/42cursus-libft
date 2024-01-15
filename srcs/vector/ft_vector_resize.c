/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:50:29 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 04:13:48 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libft_vector.h"

int	ft_vector_resize(t_vector *v, int capacity)
{
	int		status;
	void	*new_items;
	size_t	i;

	status = UNDEFINE;
	if (v)
	{
		new_items = malloc(v->item_size * capacity);
		if (new_items)
		{
			i = 0;
			ft_memcpy(new_items, v->items, v->item_size * v->total);
			v->capacity = capacity;
			status = SUCCESS;
		}
		free(v->items);
		v->items = new_items;
	}
	return (status);
}
