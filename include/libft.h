#ifndef LIBFT_H
# define LIBFT_H

#include "define.h"

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalunder(int c);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(const char *s, int fd);
char	**ft_split(char const *s, char c);
int 	ft_strchr_asaka( const  char *s, int c);
char	*ft_strchr( const  char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *dst, const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
