/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:13:10 by acash             #+#    #+#             */
/*   Updated: 2021/10/06 11:13:12 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*arrnew;
	const unsigned char	*arrold;

	if (!dst && !src)
		return (dst);
	i = 0;
	arrnew = (unsigned char *)dst;
	arrold = (unsigned char *)src;
	while (i < n)
	{
		arrnew[i] = arrold[i];
		i++;
	}
	return (dst);
}
