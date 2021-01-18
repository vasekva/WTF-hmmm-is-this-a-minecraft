/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 04:11:58 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/13 16:39:59 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			len_of_line(char *result_line)
{
	char	delimiter;
	int		len;

	len = 0;
	if (ft_strchr(result_line, '\n'))
		delimiter = '\n';
	else
		delimiter = '\0';
	while (result_line[len] != delimiter)
		len++;
	return (len);
}

char		*ft_read_line(char *remainder, int fd)
{
	char	*buff;
	int		c_w_r;

	c_w_r = 1;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (!remainder)
	{
		if ((c_w_r = read(fd, buff, BUFFER_SIZE)) < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[c_w_r] = '\0';
		remainder = ft_strdup(buff);
	}
	while (!(ft_strchr(remainder, '\n')) && c_w_r)
	{
		c_w_r = read(fd, buff, BUFFER_SIZE);
		buff[c_w_r] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

int			get_next_line(int fd, char **line)
{
	static char	*remainder[1025];
	int			len;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(remainder[fd] = ft_read_line(remainder[fd], fd)))
		return (-1);
	len = len_of_line(remainder[fd]);
	if (ft_strchr(remainder[fd], '\n'))
	{
		tmp = remainder[fd];
		*line = ft_substr(tmp, 0, len);
		remainder[fd] = ft_substr(tmp, len + 1,
				ft_strlen(remainder[fd]) - ft_strlen(*line));
		free(tmp);
		return (1);
	}
	*line = ft_substr(remainder[fd], 0, len);
	free(remainder[fd]);
	remainder[fd] = NULL;
	return (0);
}
