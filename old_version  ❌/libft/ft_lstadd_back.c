/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:15:26 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/13 08:32:13 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list *last_list;

	if (lst)
	{
		if (*lst)
		{
			last_list = ft_lstlast(*lst);
			last_list->next = new_list;
		}
		else
			*lst = new_list;
	}
}
