/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:09:37 by acash             #+#    #+#             */
/*   Updated: 2022/01/20 13:39:47 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *)s;
	while (b && i < (ft_strlen(s) + 1))
	{
		if (b[i] == (char)c)
		{
			return (&b[i]);
		}
		i++;
	}
	return ((void *)0);
}
