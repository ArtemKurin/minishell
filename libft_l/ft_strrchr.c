/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:35:30 by acash             #+#    #+#             */
/*   Updated: 2021/10/06 17:35:32 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (b[i] == (char) c)
		{
			return (&b[i]);
		}
	}
	return ((void *)0);
}
