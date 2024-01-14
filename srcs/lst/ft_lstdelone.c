/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:12:59 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/14 03:27:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft_lst.h"

void	ft_lstdelone(t_list *curr, void (*del)(void*))
{
	if (curr)
	{
		if (del && curr->content)
			(*del)(curr->content);
		free(curr);
	}
}
