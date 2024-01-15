/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:20:58 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 02:13:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTOR_H
# define LIBFT_VECTOR_H

# include <stddef.h>

# define VECTOR_INIT_CAPACITY 6
# define UNDEFINE -1
# define SUCCESS 0

typedef struct s_vector
{
	int				item_size;
	void			*items;
	size_t			capacity;
	size_t			total;
}	t_vector;

int		ft_vector_add(t_vector *v, void *item);
int		ft_vector_delete(t_vector *v, size_t index);
int		ft_vector_free(t_vector *v);
int		ft_vector_init(t_vector *v, int item_size);
int		ft_vector_resize(t_vector *v, int capacity);
int		ft_vector_set(t_vector *v, size_t index, void *item);
void	*ft_vector_get(t_vector *v, size_t index);

#endif