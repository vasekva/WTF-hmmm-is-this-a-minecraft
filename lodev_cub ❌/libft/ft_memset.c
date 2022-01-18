#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)str;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (str);
}
