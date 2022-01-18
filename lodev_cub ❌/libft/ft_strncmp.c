#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (tmp1[i] && tmp2[i] && tmp1[i] == tmp2[i] && i < n - 1)
		i++;
	return (tmp1[i] - tmp2[i]);
}
