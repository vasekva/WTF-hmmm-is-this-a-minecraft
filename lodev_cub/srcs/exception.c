/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:28:23 by jberegon          #+#    #+#             */
/*   Updated: 2021/03/15 14:28:25 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "cub3D.h"
#include <unistd.h>

static	void	ft_print_exception(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
}

void			exception(char *str)
{
	ft_print_exception(str);
}
