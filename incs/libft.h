/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:22 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/16 10:57:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* includes *******************************************************************/

# include <stddef.h>

# include "ft_integer.h"
# include "libft_lst.h"
# include "ft_vector.h"
# include "ft_string.h"
# include "ft_mem.h"

/* functions ******************************************************************/

int		ft_countwords(const char *str, const char *sep);
char	**ft_split(char const *s, char c);
char	*ft_itoa_base(int nbr, char *base);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_uitoa_base(unsigned int nbr, char *base);
char	*ft_ulltoa_base(unsigned long long nbr, char *base);
int		ft_atoi(const char *nptr);
int		ft_close(int *fd);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_ischarset(const char c, const char *set);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_itoalen_base(int n, char *base);
int		ft_itoalen(int n);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_uitoalen_base(unsigned int n, char *base);
int		ft_ulltoalen_base(unsigned long long nbr, char *base);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_xmalloc(size_t size);
void	ft_free_array(void **array);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtok(char *str, const char *delimiters);

/* FT_PRINTF ******************************************************************/

int		ft_printf(const char *str, ...) \
				__attribute__ ((format (printf, 1, 2)));
int		ft_dprintf(int fd, const char *str, ...) \
				__attribute__ ((format (printf, 2, 3)));

/* GET_NEXT_LINE **************************************************************/

// char	*get_next_line_multifd(int fd);
// char	*get_next_line(int fd);

#endif