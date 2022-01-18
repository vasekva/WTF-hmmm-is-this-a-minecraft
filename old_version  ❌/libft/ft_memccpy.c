/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 23:30:17 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/07 02:50:19 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	unsigned char	symbol;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	symbol = (unsigned char)c;
	while (n-- > 0)
	{
		*p_dst = *p_src;
		if (*p_src == symbol)
		{
			return (++p_dst);
		}
		p_dst++;
		p_src++;
	}
	return (0);
}
