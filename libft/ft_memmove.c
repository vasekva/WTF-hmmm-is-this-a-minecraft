/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:01 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/11 21:47:24 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*p_dst;
	unsigned const char		*p_src;
	size_t					num;

	num = 0;
	p_dst = dst;
	p_src = src;
	if (p_src == p_dst || len == 0)
		return (p_dst);
	if (p_dst < p_src)
	{
		while (len-- > 0)
			*p_dst++ = *p_src++;
	}
	else
	{
		p_dst += len;
		p_src += len;
		while (len--)
			*--p_dst = *--p_src;
	}
	return (dst);
}
