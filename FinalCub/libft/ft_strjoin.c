#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int param)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s1 || !s2
	|| !(tmp = malloc(sizeof(*tmp) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j])
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	if (param == 0)
		ft_strdel(&s2);
	if (param == 1)
		ft_strdel(&s1);
	if (param == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (tmp);
}