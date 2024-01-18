/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:01:20 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/18 04:07:15 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	ft_vector_trim(t_vector *v)
{
	if (!v)
		return (FAILURE);
	return (ft_vector_resize(v, v->total));
}
