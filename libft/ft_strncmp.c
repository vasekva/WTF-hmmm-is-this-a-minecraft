/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <student@jberegon.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 04:16:50 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/08 00:16:50 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *p_s1;
	unsigned char *p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (n-- != 0 && (*p_s1 || *p_s2))
	{
		if (*p_s1 < *p_s2)
			return (-1);
		if (*p_s1 > *p_s2)
			return (1);
		p_s1++;
		p_s2++;
	}
	return (0);
}
