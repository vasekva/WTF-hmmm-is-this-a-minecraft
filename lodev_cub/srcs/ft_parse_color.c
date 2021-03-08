#include "cub3D.h"


int		ft_write_color(int color, char symb_of_color, t_cub3D *cub3D, char identifier)
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

int		ft_read_color(char *str, int i, char symb_of_color, t_cub3D *cub3D, char identifier)
{
	int len;
	int color;
	int start;

	len = 0;
	color = -1;
	start = 0;
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
		color = 0;
		while (str[i] == '0')
		{
			i++;
		}
	}
	while (ft_isdigit(str[i])) // after count a length symbols in value of color 
	{
		i++;
		len++;
	}
	// printf("LEN: %d\n", len);
	color = ft_atoi(ft_substr(str, i - len, len));
	// printf("COLOR: |%d|\n", color);
	if (str[i] != ',' && str[i] != '\0')
	{
		printf("PARSE ERROR: invalid character after color value %s\n", str);
		exit (0);
	}
	else
	{
		i++;
	}
	ft_write_color(color, symb_of_color, cub3D, identifier);
	return (i);
}

int		ft_read_colors(char *str, int i, int start, t_cub3D *cub3D, char identifier)
{
	int r;
	int g;
	int b;

	// printf("STR COLOR BEFORE PARSE 1: |%s|\n", &str[i]);
	i = ft_read_color(str, i, 'R', cub3D, identifier);
	// printf("STR COLOR AFTER PARSE 1: |%s|\n", &str[i]);

	// printf("STR COLOR BEFORE PARSE 2: |%s|\n", &str[i]);
	i = ft_read_color(str, i, 'G', cub3D, identifier);
	// printf("STR COLOR AFTER PARSE 2: |%s|\n", &str[i]);

	// printf("STR COLOR BEFORE PARSE 2: |%s|\n", &str[i]);
	i = ft_read_color(str, i, 'B', cub3D, identifier);
	// printf("STR COLOR AFTER PARSE 2: |%s|\n", &str[i]);

	// printf("STRUCT COLOR R: %d\nSTRUCT COLOR G: %d\nSTRUCT COLOR B: %d\n", cub3D->floor->r, cub3D->floor->g, cub3D->floor->b);
	// printf("STR COLOR AFTER PARSE: |%s|\n", &str[i]);

	// }
	// start = i;
	// while (ft_isdigit(str[i]))
	// {
	// 	len++;
	// 	i++;
	// }
	// exit(0);
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
	// while(str[i] == ' ')
	// 	i++;
	// if (!ft_isdigit(str[i]))
	// {
	// 	if (str[i] == '-')
	// 	{
	// 		printf("PARSE ERROR: color can't be a negative value %s\n", str);
	// 		exit (0);
	// 	}
	// 	else
	// 	{
	// 		printf("PARSE ERROR: color can't be specified by non-digital value %s\n", str);
	// 		exit (0);
	// 	}
	// }
	// else
	// {
	// 	ft_read_colors(str, i, start, cub3D);
	// }
	return (0);
}