/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 16:34:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"
#include "libft.h"

int	ft_vector_add(t_vector *v, void *item)
{
	int	status;

	status = UNDEFINE;
	if (!v)
		return (status);
	if (v->total == v->capacity)
	{
		status = ft_vector_resize(v, v->capacity * 2);
		if (status != UNDEFINE)
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
