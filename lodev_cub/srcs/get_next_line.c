/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:29:39 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:29:42 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_next_line(int fd, char **line)
{
	int		i;
	int		cwr;
	char	buffer[1000000];
	char	buf;

	i = 0;
	while (1)
	{
		cwr = read(fd, &buf, 1);
		if (cwr == 0 || buf == '\n')
			break ;
		buffer[i] = buf;
		i++;
	}
	buffer[i] = '\0';
	*line = (char *)malloc(sizeof(char) * i);
	i = -1;
	while (buffer[++i] != 0)
	{
		line[0][i] = buffer[i];
	}
	line[0][i] = '\0';
	return (cwr);
}
