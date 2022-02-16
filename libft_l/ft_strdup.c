/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:34:41 by acash             #+#    #+#             */
/*   Updated: 2021/10/09 18:34:42 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*arr;

	len = ft_strlen(s1) + 1;
	arr = (char *)malloc(len);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, s1, len);
	return (arr);
}
