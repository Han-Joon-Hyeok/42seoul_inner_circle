/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:59:36 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/25 16:49:08 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define TRUE   		1
# define FALSE  		0
# define ERROR			-1
# define BUFFER_SIZE   100

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				fd;
	char			*backup;
	char			buf[BUFFER_SIZE];
	struct s_node	*next;
}	t_node;

int			ft_atoi(const char *str);
void		ft_bzero(void *dest, size_t size);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *src, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, ssize_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *ptr, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char d);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t destsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
ssize_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *small, size_t len);
char		*ft_strrchr(const char *src, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

char		*get_next_line(int fd);
t_node		*find_fd(t_node **p_head, int fd);
void		*free_fd(t_node **p_head, int fd);

#endif