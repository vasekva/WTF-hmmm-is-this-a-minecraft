#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
**================================= PART 1 =====================================
*/
void	*ft_memset(void *destination, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int param);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isprint(int c);
int		ft_isalpha(int c);


/*
**================================= PART 2 =====================================
*/

void	ft_putstr(char *s);
char	*ft_strtrim(char const *s1, char const *s2);

/*
**=============================== ADDITIONAL ===================================
*/
char	**ft_split_nl(char const *s);
void	ft_strdel(char **str);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(unsigned int nbr, char *base);
double	ft_power(double nb, int power);

#endif
