/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:57:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/17 19:24:58 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"
#include "libft.h"

int	ft_vector_delete(t_vector *v, size_t index)
{
	int		status;
	void	*start;
	void	*end;

	status = UNDEFINE;
	if (v && index < v->total)
	{
		start = ft_vector_get(v, index);
		end = ft_vector_get(v, v->total - 1);
		ft_memcpy2(start, start + v->item_size, end);
		v->total--;
		if (v->total == v->capacity >> 2)
			ft_vector_resize(v, v->capacity >> 2);
	}
	return (status);
}
