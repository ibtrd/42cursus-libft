/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:55:07 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/18 04:02:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	ft_vector_set(t_vector *v, size_t index, void *item)
{
	int	status;

	status = UNDEFINE;
	if (!v)
		return (status);
	if (index < v->total)
	{
		ft_memcpy(v->items + index * v->item_size, item, v->item_size);
		status = SUCCESS;
	}
	return (status);
}
