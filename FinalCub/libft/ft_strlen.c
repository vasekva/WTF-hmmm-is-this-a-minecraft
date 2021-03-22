#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned char	*str;
	int				i;

	if (!s)
		return (0);
	i = 0;
	str = (unsigned char *)s;
	while (str[i])
		i++;
	return (i);
}