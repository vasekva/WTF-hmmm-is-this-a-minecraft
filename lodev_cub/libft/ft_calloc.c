#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(nmemb * size)))
		return (NULL);
	while (i < nmemb * size)
		dest[i++] = 0;
	return (dest);
}
