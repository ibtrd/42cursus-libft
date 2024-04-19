/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:10:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/19 22:10:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vector_get(t_vector *v, size_t index)
{
	void	*ptr;

	if (!v || index >= v->total)
		return (NULL);
	ptr = v->ptr + index * v->size;
	return (ptr);
}
