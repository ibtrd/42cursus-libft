/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:07:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/19 09:08:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_vector.h"

int	ft_vector_free(t_vector *v)
{
	int	status;

	status = UNDEFINED;
	if (v)
	{
		free(v->items);
		v->items = NULL;
		status = SUCCESS;
	}
	return (status);
}
