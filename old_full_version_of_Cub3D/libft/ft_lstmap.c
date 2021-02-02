/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberegon <jberegon@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:43:08 by jberegon          #+#    #+#             */
/*   Updated: 2020/11/13 16:45:11 by jberegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *list;
	t_list *new_list;

	list = NULL;
	while (lst)
	{
		if (!(new_list = ft_lstnew(f(lst->content))))
		{
			del(lst);
			free(lst);
			return (NULL);
		}
		ft_lstadd_back(&list, new_list);
		lst = lst->next;
	}
	return (list);
}
