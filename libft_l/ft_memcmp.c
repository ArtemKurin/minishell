/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:58:05 by acash             #+#    #+#             */
/*   Updated: 2021/10/08 14:58:06 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*arr1;
	const unsigned char	*arr2;

	arr1 = s1;
	arr2 = s2;
	i = 0;
	while (i < n)
	{
		if (arr1[i] != arr2[i])
		{
			return (arr1[i] - arr2[i]);
		}
		i++;
	}
	return (0);
}
