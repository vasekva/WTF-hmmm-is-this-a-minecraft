double	ft_power(double nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}