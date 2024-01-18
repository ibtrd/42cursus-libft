/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_join.c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:55:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/18 04:48:32 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_join(t_vector *v, void *items, size_t n)
{
	int	status;

	if (!v)
		return (FAILURE);
	while (v->total + v->null_term + n >= v->capacity)
	{
		status = ft_vector_resize(v, v->capacity << 1);
		if (status != SUCCESS)
			return (status);
	}
	ft_memcpy(v->items + v->item_size * v->total, items, v->item_size * n);
	v->total += n;
	return (status);
}
