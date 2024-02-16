/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:18:27 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/15 16:22:07 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

size_t	ft_strlen_protected(const char *str);
size_t	ft_strnlen(const char *str, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin2(char const *s1, char const *s2, char const *s3);

#endif