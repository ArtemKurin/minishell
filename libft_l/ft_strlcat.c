/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:32:31 by acash             #+#    #+#             */
/*   Updated: 2022/01/19 20:56:11 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		result;

	i = 0;
	j = 0;
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	result = ft_strlen(src) + ft_strlen(dst);
	if (dstsize == 0)
	{
		dst[0] = '\0';
		return (result);
	}
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}
