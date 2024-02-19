/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/19 17:49:34 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* includes *******************************************************************/

# include <stddef.h>

# include "ft_char.h"
# include "ft_integer.h"
# include "ft_lst.h"
# include "ft_mem.h"
# include "ft_string.h"
# include "ft_vector.h"

/* functions ******************************************************************/

char	**ft_split(char const *s, char c);
char	*ft_itoa_base(int nbr, char *base);
char	*ft_itoa(int n);
char	*ft_uitoa_base(unsigned int nbr, char *base);
char	*ft_ulltoa_base(unsigned long long nbr, char *base);
int		ft_atoi(const char *nptr);
int		ft_close(int *fd);
int		ft_countwords(const char *str, const char *sep);
int		ft_itoalen_base(int n, char *base);
int		ft_itoalen(int n);
int		ft_uitoalen_base(unsigned int n, char *base);
int		ft_ulltoalen_base(unsigned long long nbr, char *base);
void	ft_free_array(void **array);
void	ft_free_2darray_char(char **array);

/* FT_PRINTF ******************************************************************/

int		ft_printf(const char *str, ...) \
				__attribute__ ((format (printf, 1, 2)));
int		ft_dprintf(int fd, const char *str, ...) \
				__attribute__ ((format (printf, 2, 3)));

#endif