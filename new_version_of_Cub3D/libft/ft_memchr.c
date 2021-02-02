/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:30:56 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/04 21:03:07 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	symbol;

	p_s = (unsigned char*)s;
	symbol = (unsigned char)c;
	if (n != 0)
	{
		while (n-- > 0)
		{
			if (*p_s++ == symbol)
				return (p_s - 1);
		}
	}
	return (0);
}
