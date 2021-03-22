#include "libft.h"

void	ft_strdel(char **str)
{
	if (!str)
		return ;
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}