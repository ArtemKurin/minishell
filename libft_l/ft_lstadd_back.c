/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:20:42 by acash             #+#    #+#             */
/*   Updated: 2022/01/27 20:17:17 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_vars **lst, t_vars *new)
{
	t_vars	*mylist;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		mylist = ft_lstlast(*lst);
		mylist->next = new;
	}
}
