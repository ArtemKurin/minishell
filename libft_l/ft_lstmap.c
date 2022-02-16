/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:02:48 by acash             #+#    #+#             */
/*   Updated: 2022/01/18 14:55:53 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vars	*ft_lstmap(t_vars *lst, void *(*f)(void *), void (*del)(void *))
{
	t_vars	**mylist;
	t_vars	*save;
	t_vars	*newlist;

	if (!lst || !f)
		return (NULL);
	save = NULL;
	mylist = &save;
	while (lst)
	{
		newlist = ft_lstnew(f(lst->var));
		if (!newlist)
		{
			ft_lstclear(mylist, del);
			return (NULL);
		}
		ft_lstadd_back(mylist, newlist);
		lst = lst->next;
	}
	return (*mylist);
}
