/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:53:24 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/04 21:25:43 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p_s1;
	unsigned const char	*p_s2;

	p_s1 = s1;
	p_s2 = s2;
	if (n != 0)
	{
		while (n-- > 0)
		{
			if (*p_s1++ != *p_s2++)
				return (*--p_s1 - *--p_s2);
		}
	}
	return (0);
}
