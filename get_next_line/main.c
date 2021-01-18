/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:01:14 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/12 20:08:18 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		i;
	char	*line;

	//fd = open("text.txt", O_RDONLY);
	fd = open("huge_file", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	if (i == 0)
	{
		printf("%s", line);
		free(line);
	}
	if (i < 0)
		printf("All is good");
}
