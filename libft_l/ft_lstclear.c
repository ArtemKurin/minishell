/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:41:52 by acash             #+#    #+#             */
/*   Updated: 2022/01/18 14:54:28 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_vars **lst, void (*del)(void *))
{
	t_vars	*mylist;

	if (!lst)
		return ;
	if (del)
	{
		while (*lst)
		{
			mylist = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = mylist;
		}
	}
	*lst = NULL;
}
