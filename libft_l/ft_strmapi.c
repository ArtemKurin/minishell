/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:58:57 by acash             #+#    #+#             */
/*   Updated: 2021/10/13 10:58:58 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (ft_strdup(""));
	arr = ft_strdup(s);
	if (arr == NULL)
		return (NULL);
	while (arr[i])
	{
		arr[i] = f(i, arr[i]);
		i++;
	}
	return (arr);
}
