/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:08:30 by jberegon          #+#    #+#             */
/*   Updated: 2020/12/12 20:09:53 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *buff);
char 	*ft_strjoin(char *remainder, char *buff);
char 	*ft_strchr(char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(char *str);

#endif
