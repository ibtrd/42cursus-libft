/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:38:32 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/18 04:02:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_init(t_vector *v, int item_size)
{
	v->item_size = item_size;
	v->items = malloc(item_size * VECTOR_INIT_CAPACITY);
	if (!v->items)
		return (UNDEFINE);
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	return (SUCCESS);
}
