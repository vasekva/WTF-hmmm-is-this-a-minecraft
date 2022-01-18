#include "libft.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_int;
	char	*dest;

	nb_int = ft_atoi_base(nbr, base_from);
	dest = ft_itoa_base(nb_int, base_to);
	return (dest);
}
