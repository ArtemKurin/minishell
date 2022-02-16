/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:42:51 by acash             #+#    #+#             */
/*   Updated: 2022/01/28 16:19:37 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vars	*ft_lstnew(char *var)
{
	t_vars	*list;

	list = (t_vars *)malloc(sizeof(t_vars));
	if (list)
	{
		list->var = var;
		list->next = NULL;
	}
	return (list);
}
