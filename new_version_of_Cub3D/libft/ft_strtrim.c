/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 02:28:51 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/10 23:37:10 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_symbol(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	start;
	size_t	end;
	char	*str;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && check_symbol(s2, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && check_symbol(s2, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
