/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <student@jberegon.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 05:06:21 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/07 07:07:58 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *havstack, const char *needle, size_t len)
{
	char		*p_havstack;
	size_t		needle_len;
	size_t		i;
	size_t		j;

	i = 0;
	p_havstack = (char*)havstack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
	{
		return (char *)havstack;
	}
	while (p_havstack[i] && i <= (len - needle_len))
	{
		j = 0;
		while (p_havstack[i + j] && needle[j] && i + j < len &&
		havstack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return (&p_havstack[i]);
		i++;
	}
	return (NULL);
}
