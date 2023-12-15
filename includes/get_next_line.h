/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:09:37 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/15 03:01:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft_str.h"

# include <unistd.h> //Read()
# include <stdlib.h> //free()
# include <limits.h> //MAX_INT

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buffer
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}	t_buffer;

char		*get_next_line(int fd);

char		*build_next_line(char *buffer, int fd);
char		*gnl_assembler(char *next_line, char *buffer, int fd);
int			gnl_newline_check(char *str);
char		*gnl_join(char *prev_str, char *buffer);
size_t		gnl_len_to_newline(char *str);
void		gnl_reinit_buffer(char	*buffer);

char		*get_next_line_multifd(int fd);

char		*gnl_get_buffer(t_buffer **head, int fd);
void		gnl_free_fd(t_buffer **head, int fd);
t_buffer	*gnl_free_all(t_buffer *curr);

#endif