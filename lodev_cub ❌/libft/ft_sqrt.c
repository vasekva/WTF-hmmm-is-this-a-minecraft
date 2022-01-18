double	ft_sqrt(double nb)
{
	int sqrt;

	sqrt = 0;
	if (nb > 2147395600)
		return (0);
	while (sqrt * sqrt <= nb)
	{
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
