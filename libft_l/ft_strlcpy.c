/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:01:29 by acash             #+#    #+#             */
/*   Updated: 2021/10/06 13:01:32 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	char		*arrnew;
	const char	*arrold;

	i = 0;
	arrnew = dst;
	arrold = src;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1)
	{	
		if (arrold[i] == '\0')
			break ;
		arrnew[i] = arrold[i];
		i++;
	}
	if (dstsize != 0)
		arrnew[i] = '\0';
	return (ft_strlen(src));
}
