/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert_ptr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/19 22:09:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_mem.h"

int	ft_vector_insert_ptr(t_vector *v, void *item, size_t index)
{
	if (!v || index > v->total)
		return (FAILURE);
	if (v->total == v->capacity)
		if (ft_vector_resize(v, v->capacity << 1))
			return (FAILURE);
	ft_memmove(v->ptr + v->size * (index + 1), v->ptr + v->size * index,
		v->size * (v->total - index));
	*((void **)v->ptr + index) = item;
	v->total++;
	return (SUCCESS);
}
