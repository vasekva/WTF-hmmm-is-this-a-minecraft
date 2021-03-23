# include "includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

char	*ft_add_spaces(char *str, int add)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	dst = malloc(len + add + 1);
	dst[len + add] = '\0';
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	while (add)
	{
		dst[i] = ' ';
		add--;
		i++;
	}
	// free(str);
	return (dst);
}

int main(void)
{
	char *s1 = "hello";
	char *s2 = "hell";
	int add = ft_strlen(s1) - ft_strlen(s2);
	char *res = ft_add_spaces(s2, add);
	printf("%s|| \n%s||\n", s1, res);
}