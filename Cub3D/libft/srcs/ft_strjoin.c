#include "libft.h"

int	ft_fill_s1(char *str, char *s1, int *j, int i)
{
	int	n;

	n = *j;
	i = 0;
	while (s1[i])
	{
		str[n++] = s1[i];
		i++;
	}
	*j = n;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		i = ft_fill_s1(str, s1, &j, i);
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	if (s1 != NULL)
		free(s1);
	return (str);
}
