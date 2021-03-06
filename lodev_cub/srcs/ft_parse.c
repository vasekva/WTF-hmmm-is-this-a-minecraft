#include "cub3D.h"

int		ft_check_specifier(char *str)
{
	int check;

	check = 0;
	if (str[0] == 'R')
		check++;
	if (str[0] == 'S')
		check++;
	if (str[0] == 'F')
		check++;
	if (str[0] == 'C')
		check++;
	if (str[0] == 'N' && str[1] == 'O')
		check++;
	if (str[0] == 'S' && str[1] == 'O')
		check++;
	if (str[0] == 'W' && str[1] == 'E')
		check++;
	if (str[0] == 'E' && str[1] == 'A')
		check++;
	if (str[0] >= 49 || str[0] <= 57)
		check++;
	if (check == 1)
		printf("-----------STR %s верна\n", str);						
	return (check);			
}

int		check_line_with_space(char *line)
{
	int c;

	c = 0;
	while (line[c])
	{
		if (line[c] != ' ')
		{
			if (line[c] < 49 || line[c] > 57)
			{
				printf("PARSE ERROR: HAVE A SPACE BEFORE PARAM\n");
				exit(0);
				return (-1);
			}
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
					if (ft_check_specifier(&line[0]) == 0)
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