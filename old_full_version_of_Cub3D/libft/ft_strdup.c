/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 05:30:08 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/05 05:53:35 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	n;

	n = ft_strlen(s1) + 1;
	str = malloc(n);
	if (str == NULL)
		return (NULL);
	(void)ft_memcpy(str, s1, n);
	return (str);
}
