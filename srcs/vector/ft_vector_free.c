/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:07:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 02:11:26 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_vector.h"

int	ft_vector_free(t_vector *v)
{
	int	status;

	status = UNDEFINE;
	if (v)
	{
		free(v->items);
		v->items = NULL;
		status = SUCCESS;
	}
	return (status);
}
