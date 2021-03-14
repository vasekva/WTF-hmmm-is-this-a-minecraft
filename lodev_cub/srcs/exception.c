#include "exception.h"
#include "cub3D.h"
#include <unistd.h>

void	ft_print_exception(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
}

int		equals(char *constant, char *str)
{
	int i;

	i = 0;
	if (ft_strlen(constant) != ft_strlen(str))
		return (-1);
	while (constant[i] != '\0')
	{
		if (constant[i] != str[i])
			return (-1);
		i++;
	}
	return (1);
}

void	exception(char *str)
{
	ft_print_exception(str);
}