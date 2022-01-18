#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (0);
	while (src[i])
		i++;
	if (!size)
		return (i);
	while (src[j] && j < size - 1 && size > 0)
	{
		dest[j] = src[j];
		j++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (i);
}
