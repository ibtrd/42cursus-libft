/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:09:37 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/21 22:13:46 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> //Read()
# include <stdlib.h> //free()
# include <limits.h> //MAX_INT

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*gnl_assembler(char *cache, int fd);
char	*gnl_joincache(char *cache, char *buffer, ssize_t rd);
char	*gnl_trimcache(char *cache);
char	*gnl_trimline(char *cache);
int		gnl_newlinecheck(char *buffer);
size_t	ft_strlen(char const *str);
void	ft_strlcpy(char *dst, const char *src, size_t size);
void	gnl_freecache(char **cache_array);

#endif