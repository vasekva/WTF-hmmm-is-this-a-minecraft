#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)str;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
