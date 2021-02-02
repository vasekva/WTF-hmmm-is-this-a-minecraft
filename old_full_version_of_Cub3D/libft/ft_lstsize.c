/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 08:40:29 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/12 08:50:05 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int len;

	len = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			len++;
		}
	}
	return (len);
}
