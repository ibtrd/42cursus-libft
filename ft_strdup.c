/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:31:29 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/13 09:47:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	ptr = NULL;
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr)
		ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
