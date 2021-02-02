/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:16:02 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/08 19:44:48 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			strlength;
	const	char	*osrc;

	if (dst == NULL || src == NULL)
		return (0);
	osrc = src;
	strlength = size;
	if (strlength != 0)
	{
		while (--strlength != 0)
		{
			if ((*dst++ = *src++) == '\0')
			{
				break ;
			}
		}
	}
	if (strlength == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
