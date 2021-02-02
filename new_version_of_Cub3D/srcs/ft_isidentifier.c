
int		ft_isidentifier(char *str)
{
	int i;

	i = 0;
	if (str[i] == 'R' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'S' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'F' && str[i + 1] == ' ')
		return (1);
	if (str[i] == 'C' && str[i + 1] == ' ')
		return (1);						
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		return (1);
	return (-1);
}