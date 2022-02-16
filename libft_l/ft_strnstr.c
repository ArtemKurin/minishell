/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:40:14 by acash             #+#    #+#             */
/*   Updated: 2022/01/27 15:53:04 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	i = 0;
	j = 0;
	if (str2[i] == '\0')
		return (str1);
	while (i < len && str1[i])
	{
		if (str1[i] == str2[0])
		{
			while (str2[j] && str1[i + j] == str2[j] && i + j < len)
			{
				if (!str2[j + 1])
					return (&str1[i]);
				j++;
			}
		}
		i++;
	}
	return ((void *)0);
}
