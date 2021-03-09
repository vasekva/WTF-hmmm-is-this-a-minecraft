#include "cub3D.h"

static int		ft_write_color(int color, char symb_of_color, t_cub3D *cub3D, char identifier)
{
	if (identifier == 'F')
	{
		if (symb_of_color == 'R')
			cub3D->floor->r = color;
		if (symb_of_color == 'G')
			cub3D->floor->g = color;
		if (symb_of_color == 'B')
			cub3D->floor->b = color;
	}
	if (identifier == 'C')
	{
		if (symb_of_color == 'R')
			cub3D->ceiling->r = color;
		if (symb_of_color == 'G')
			cub3D->ceiling->g = color;
		if (symb_of_color == 'B')
			cub3D->ceiling->b = color;
	}
	return (0);
}

static int		ft_skip_spaces_and_zeros(char *str, int i)
{
	while (str[i] == ' ') // skip all spaces before the number
		i++;
	if (!ft_isdigit(str[i])) // if symbol after space isn't a digit value - ERROR
	{
		if (str[i] == '-')
		{
			printf("PARSE ERROR: color can't be a negative value %s\n", str);
		}
		else
		{
			printf("PARSE ERROR: color can't be not a digit value %s\n", str);
		}
		exit (0);
	}
	if (str[i] == '0') // if symbol equals zero - set a color and skip all zero symbols  
	{
		while (str[i] == '0')
		{
			i++;
		}
	}
	return (i);
}

static int		ft_read_color(char *str, int i, char value, t_cub3D *cub3D, char identifier)
{
	int len;
	int color;
	int start;

	len = 0;
	color = 0;
	start = 0;
	i = ft_skip_spaces_and_zeros(str, i) - 1;
	while (ft_isdigit(str[++i])) // after count a length symbols in value of color 
		len++;
	color = ft_atoi(ft_substr(str, i - len, len));
	if (color > 255)
	{
		printf("PARSE ERROR: value of color can't be bigger than 255 %s\n", str);
		exit (0);
	}
	if (str[i] != ',' && str[i] != '\0')
	{
		printf("PARSE ERROR: invalid character after color value %s\n", str);
		exit (0);
	}
	else
		i++;
	ft_write_color(color, value, cub3D, identifier);
	return (i);
}

static int		ft_read_colors(char *str, int i, int start, t_cub3D *cub3D, char identifier)
{
	if (identifier == 'F')
	{
		if (cub3D->floor->r != -1 || cub3D->floor->g != -1 || cub3D->floor->b != -1)
		{
			printf("Parameter F has already been specified!\n");
			exit(0);
		}
	}
	if (identifier == 'C')
	{
		if (cub3D->ceiling->r != -1 || cub3D->ceiling->g != -1 || cub3D->ceiling->b != -1)
		{
			printf("Parameter C has already been specified!\n");
			exit(0);
		}
	}
	i = ft_read_color(str, i, 'R', cub3D, identifier);
	i = ft_read_color(str, i, 'G', cub3D, identifier);
	i = ft_read_color(str, i, 'B', cub3D, identifier);
	return (0);
}

int		ft_parse_color(char *str, t_cub3D *cub3D)
{
	int i;
	int start;
	char identifier;

	i = 1;
	start = 0;
	identifier = str[0];
	if (str[i] != ' ')
	{
		printf("PARSE ERROR: string can't be without a space after identifier %s\n", str);
		exit (0);
	}
	i++;
	ft_read_colors(str, i, start, cub3D, identifier);
	return (0);
}