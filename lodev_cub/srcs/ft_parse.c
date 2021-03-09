#include "cub3D.h"

int		ft_check_specifier(char *str, t_cub3D *cub3D)
{
	int check;

	check = 0;
	if (str[0] == 'R')
	{
		ft_parse_screen_size(str, cub3D);
		check++;
	}
	if (str[0] == 'S' || (str[0] == 'S' && str[0] == 'O')
		|| (str[0] == 'N' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A'))
	{
		ft_parse_path(str, cub3D);
		check++;
	}
	if (str[0] == 'F' || str[0] == 'C')
	{
		ft_parse_color(str, cub3D);
		if (str[0] == 'F')
			printf("F: \nR: |%d|, G: |%d|, B: |%d|\n\n", cub3D->floor->r, cub3D->floor->g, cub3D->floor->b);
		if (str[0] == 'C')
			printf("C: \nR: |%d|, G: |%d|, B: |%d|\n\n", cub3D->ceiling->r, cub3D->ceiling->g, cub3D->ceiling->b);
		check++;
	}
	if (str[0] >= 49 && str[0] <= 57)
	{
		ft_parse_map(str);
		check++;
	}					
	return (check);			
}

int		check_line_with_space(char *line, t_cub3D *cub3D)
{
	int c;
	int	is_first_symb;
	int has_digit;

	c = 0;
	has_digit = 0;
	is_first_symb = 1;
	while (line[c])
	{
		if (ft_isdigit(line[c]))
		{
			has_digit = 1;
			break;
		}
		c++;
	}
	if (has_digit)
	{
		if (!ft_check_structs(cub3D))
		{
			printf("PARSE ERROR: not all parameters are filled in! The map must be the last %s\n", line);
			exit(0);
		}
		else
			ft_parse_map(line);

	}
	else
	{
		printf("PARSE ERROR: empty string can't contain characters %s\n", line);
		exit(0);
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
			if (line[0] == ' ')
			{
				check_line_with_space(line, cub3D);
			}
			if (ft_isalpha(line[0]))
			{
				if (line[ft_strlen(line) - 1] == ' ')
				{
					printf("PARSE ERROR: string can't end with space symbol %s\n", line);
					exit(0);
				}
				if (ft_check_specifier(line, cub3D) == 0)
				{
					printf("PARSE ERROR: unknown param in str: %s\n", line);
					exit(0);
				}
			}
			if (i == 0)
				break;
    	}

    }
}