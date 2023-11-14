/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:50:15 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/11 15:52:39 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(const char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	start = 0;
	while (ft_ischarset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_ischarset(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

static int	ft_ischarset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
