/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:45:18 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/04 22:03:11 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char *p_dest;

	p_dest = destination;
	if (n != 0)
	{
		while (n-- != 0)
			*p_dest++ = (unsigned char)c;
	}
	return (destination);
}
