#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int temp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = -n;
	}
	else
		temp = n;
	if (temp < 10)
		ft_putchar_fd(temp + '0', fd);
	else
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putchar_fd(temp % 10 + '0', fd);
	}
}
