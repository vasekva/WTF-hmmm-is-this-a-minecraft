#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dst = malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
