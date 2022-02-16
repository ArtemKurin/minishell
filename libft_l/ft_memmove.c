/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:58:28 by acash             #+#    #+#             */
/*   Updated: 2021/10/06 11:58:29 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*arrnew;
	const unsigned char	*arrold;

	if (!dst && !src)
		return ((void *)0);
	arrnew = (unsigned char *)dst;
	arrold = (unsigned char *)src;
	if (arrnew > arrold)
	{
		while (len--)
		{
			arrnew[len] = arrold[len];
		}
	}
	else if (arrnew < arrold)
		ft_memcpy(dst, src, len);
	return (dst);
}
