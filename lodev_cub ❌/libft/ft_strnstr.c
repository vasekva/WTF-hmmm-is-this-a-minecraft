#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (to_find[j] && to_find[j] == str[i + j] && (i + j) < len)
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
		j = 0;
	}
	return (0);
}
