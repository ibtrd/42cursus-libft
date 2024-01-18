/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/18 04:36:19 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_add(t_vector *v, void *item)
{
	int	status;

	if (!v)
		return (FAILURE);
	if (v->total + v->null_term == v->capacity)
	{
		status = ft_vector_resize(v, v->capacity << 1);
		if (status != FAILURE)
		{
			ft_memcpy(v->items + v->item_size * v->total, item, v->item_size);
			v->total++;
		}
	}
	else
	{
		ft_memcpy(v->items + v->item_size * v->total, item, v->item_size);
		v->total++;
		status = SUCCESS;
	}
	return (status);
}
