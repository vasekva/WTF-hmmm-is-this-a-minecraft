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
		if (ft_check_structs(cub3D) == -1)
		{
			printf("PARSE ERROR: not all parameters are filled in! The map must be the last %s\n", line);
			exit(0);
		}
		else
			ft_parse_array(line, cub3D);

	}
	else
	{
		printf("PARSE ERROR: empty string can't contain characters %s\n", line);
		exit(0);
	}
	return (0);
}

void	ft_print_array(t_cub3D *cub3D)
{
	int i = 0;

	printf("SIZE: %d\n", cub3D->array->size);
	while (cub3D->array->map_arr[i])
	{
		printf("%s\n", cub3D->array->map_arr[i]);
		i++;
	}
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
			if (line[0] == ' ')
			{
				check_line_with_space(line, cub3D);
			}
			if (line[0] >= '0' && line[0] <= '9')
			{
				ft_parse_array(line, cub3D);
				printf("ARRAY SIZE: %d\n", cub3D->array->size);
			}
			if (i == 0)
				break;
    	}
		if (cub3D->array->size == 0)
		{
			printf("PARSE ERROR: there's no map in the file %s\n", line);
			exit(0);			
		}
		cub3D->array->map_arr = (char **)malloc(sizeof(char) * (cub3D->array->size + 1));
		if (!cub3D->array->map_arr)
		{
			printf("PARSE ERROR: map_arr malloc error \n");
			exit(0);	
		}
		cub3D->array->map_arr[cub3D->array->size] = NULL;
		close(fd);
		fd = open(cub3D->file_path, O_RDONLY);

		int num_of_line;
		num_of_line = 0;
		while((i = get_next_line(fd, &line)) >= 0) // read map
    	{
			int c;

			c = 0;
			if (line[0] == '1' || line[0] == ' ')
			{
				if (num_of_line == cub3D->array->size)
					break;
				cub3D->array->map_arr[num_of_line] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
				ft_strcpy(cub3D->array->map_arr[num_of_line], line);
				num_of_line++;
			}
			if (i == 0)
				break;
    	}
		cub3D->array->map_arr[cub3D->array->size] = NULL;
		ft_print_array(cub3D);
    }
}