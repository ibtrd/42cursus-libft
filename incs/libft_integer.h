/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_integer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:58:54 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/18 01:16:42 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTEGER_H
# define LIBFT_INTEGER_H

int		ft_strtoi(const char *ptr, char **endptr);
long	ft_strtol(const char *ptr, char **endptr);
int		ft_abs(int x);

#endif