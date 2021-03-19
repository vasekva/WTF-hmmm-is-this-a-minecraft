#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)str;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((unsigned char *)&str[i]);
		i++;
	}
	return (0);
}
