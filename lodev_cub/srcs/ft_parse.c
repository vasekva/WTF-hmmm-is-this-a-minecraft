#include "cub3D.h"

int		ft_check_mapline(char *str)
{
	char	c;

	c = 0;
	while (str[c])
	{
		if (str[0] < 49 || str[0] > 57)
		{
			printf("PARSE ERROR: unknown digit at the start of a line %s\n", str);
			exit (0);
		}
		if ((c == ft_strlen(str) - 1) && (str[c] < 49 || str[c] > 57))
		{
			printf("PARSE ERROR: unknown digit at the end of a line %s\n", str);
			exit (0);
		}
		if (str[c] != 'S' && str[c] != 'N' && str[c] != 'W' && str[c] != 'E'
			&& (str[c] < 48 || str[c] > 57))
		{
			printf("PARSE ERROR: unknown digit in line %s\n", str);
			exit (0);
		}
		c++;
	}
	return (0);
}

// int		ft_parse_screen_size(char *str, t_cub3D *cub3D)
// {
// 	int c;
// 	int	count_values;
// 	int	len;

// 	c = 1;
// 	count_values = 0;
// 	len = 0;
// 	if (str[c] != ' ')
// 	{
// 		printf("PARSE ERROR: value string can't be without space after param %s\n", str);
// 		exit(0);
// 	}

// 	while (str[c] == ' ')
// 		c++;
// 	if (!ft_isdigit(str[c]))
// 	{
// 		if (str[c] == '-')
// 				printf("PARSE ERROR: screen size can't be a negative value %s\n", str);
// 		else
// 			printf("PARSE ERROR: screen size can't be not a digit value %s\n", str);
// 		exit(0);
// 	}
// 	while (ft_isdigit(str[c]))
// 	{
// 		len++;
// 		c++;
// 	}

// 	cub3D->screen->w = ft_parse_int(ft_substr(str, c - len, len));
// 	len = 0;
// 	while (str[c] == ' ')
// 		c++;
// 	if (!ft_isdigit(str[c]))
// 	{
// 		if (str[c] == '-')
// 				printf("PARSE ERROR: screen size can't be a negative value %s\n", str);
// 		else
// 			printf("PARSE ERROR: screen size can't be not a digit value %s\n", str);
// 		exit(0);
// 	}
// 	while (ft_isdigit(str[c]))
// 	{
// 		len++;
// 		c++;
// 	}

// 	cub3D->screen->h = ft_parse_int(ft_substr(str, c - len, len));

// 	printf("W: %d H: %d\n", cub3D->screen->w, cub3D->screen->h);
// 	exit(0);
// 	return (0);
// }

int		ft_check_specifier(char *str, t_cub3D *cub3D)
{
	int check;

	check = 0;
	if (str[0] == 'R')
	{
		ft_parse_screen_size(str, cub3D);
		check++;
	}
	if (str[0] == 'S')
	{
		check++;
	}
	if (str[0] == 'F')
	{
		check++;
	}
	if (str[0] == 'C')
	{
		check++;
	}
	if (str[0] == 'N' && str[1] == 'O')
	{
		check++;
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		check++;
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		check++;
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		check++;
	}
	if (str[0] >= 49 && str[0] <= 57)
	{
		ft_check_mapline(str);
		check++;
	}					
	return (check);			
}

int		check_line_with_space(char *line)
{
	int c;
	int	is_first_symb;

	c = 0;
	is_first_symb = 1;
	while (line[c])
	{
		if (line[c] != ' ')
		{
			ft_check_mapline(&line[c]);
			break;
		}
		c++;
	}
	return (0);
}

void	ft_parse(t_cub3D *cub3D)
{
	if (cub3D->file_path)
    {
		int 	fd;
		char	*line;
		int		i;

		fd = open(cub3D->file_path, O_RDONLY);
		i = 0;
    	while((i = get_next_line(fd, &line)) >= 0) // get a string
    	{
    	    printf("STR: %s\n", line);
			int c = 0;
			while (line[c] != '\0') // check each symbol of string
			{
				if (line[0] == ' ')
				{
					check_line_with_space(line);
				}
				else
				{
					if (line[ft_strlen(line) - 1] == ' ')
					{
						printf("PARSE ERROR: string can't end with space symbol %s\n", &line[c]);
						exit(0);
					}
					if (ft_check_specifier(&line[0], cub3D) == 0)
					{
						printf("PARSE ERROR: unknown param in str: %s\n", &line[c]);
						exit(0);
					}
				}
				c++;
			}

			if (i == 0)
				break;
    	}

    }
}