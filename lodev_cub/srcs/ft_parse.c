/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:28:41 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:28:43 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_check_specifier(char *str, t_cub3D *cub3d)
{
	int check;

	check = 0;
	if (str[0] == 'R')
	{
		ft_parse_screen_size(str, cub3d);
		check++;
	}
	if (str[0] == 'S' || (str[0] == 'S' && str[0] == 'O')
		|| (str[0] == 'N' && str[1] == 'O')
		|| (str[0] == 'W' && str[1] == 'E')
		|| (str[0] == 'E' && str[1] == 'A'))
	{
		ft_parse_path(str, cub3d);
		check++;
	}
	if (str[0] == 'F' || str[0] == 'C')
	{
		ft_parse_color(str, cub3d);
		check++;
	}
	return (check);
}

int		check_line_with_space(char *line, t_cub3D *cub3d)
{
	int c;
	int has_digit;

	c = 0;
	has_digit = 0;
	while (line[c])
	{
		if (ft_isdigit(line[c]))
		{
			has_digit = 1;
			break ;
		}
		c++;
	}
	if (has_digit)
	{
		if (ft_check_structs(cub3d) == -1)
			exception(FIVETEEN);
		else
			ft_parse_array(line, cub3d);
	}
	else
		exception(SIXTEEN);
	return (0);
}

void	ft_read_file(int fd, t_cub3D *cub3d)
{
	int		i;
	char	*line;

	while ((i = get_next_line(fd, &line)) >= 0)
	{
		if (ft_isalpha(line[0]))
		{
			if (line[ft_strlen(line) - 1] == ' ')
				exception(ONE);
			if (ft_check_specifier(line, cub3d) == 0)
				exception(TWO);
		}
		if (line[0] == ' ')
			check_line_with_space(line, cub3d);
		if (line[0] >= '0' && line[0] <= '9')
			ft_parse_array(line, cub3d);
		if (i == 0)
			break ;
	}
}

void	ft_read_map_from_file(int fd, t_cub3D *cub3d)
{
	int		i;
	char	*line;
	int		num_of_line;

	while ((i = get_next_line(fd, &line)) >= 0)
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			if (num_of_line == cub3d->array->size)
				break ;
			cub3d->array->map_arr[num_of_line] =
					(char *)malloc(sizeof(char) * ft_strlen(line) + 1);
			if (!cub3d->array->map_arr[num_of_line])
			{
				exception(SEVENTEEN);
			}
			ft_strcpy(cub3d->array->map_arr[num_of_line], line);
			num_of_line++;
		}
		if (i == 0)
			break ;
	}
	cub3d->array->map_arr[cub3d->array->size] = NULL;
}

void	ft_parse(t_cub3D *cub3d)
{
	int		fd;

	if (cub3d->file_path)
	{
		fd = open(cub3d->file_path, O_RDONLY);
		if (fd == -1)
			exception(THIRTYTWO);
		ft_read_file(fd, cub3d);
		close(fd);
		if (cub3d->array->size == 0)
			exception(THREE);
		cub3d->array->map_arr = (char **)malloc(sizeof(char)
												* (cub3d->array->size + 1));
		if (!cub3d->array->map_arr)
			exception(SEVENTEEN);
		cub3d->array->map_arr[cub3d->array->size] = NULL;
		fd = open(cub3d->file_path, O_RDONLY);
		if (fd == -1)
			exception(THIRTYTWO);
		ft_read_map_from_file(fd, cub3d);
		close(fd);
		ft_check_array(cub3d);
		ft_print_array(cub3d);
	}
}
