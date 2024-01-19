/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:55:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/19 09:08:21 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_set(t_vector *v, size_t index, void *item)
{
	int	status;

	if (!v)
		return (FAILURE);
	status = UNDEFINED;
	if (index < v->total)
	{
		ft_memcpy(v->items + index * v->item_size, item, v->item_size);
		status = SUCCESS;
	}
	return (status);
}
