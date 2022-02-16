/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:51:26 by acash             #+#    #+#             */
/*   Updated: 2021/10/11 20:51:27 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_skipb(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	int				flag;

	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_skipend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	return (ft_substr(s1, ft_skipb(s1, set),
			(ft_skipend(s1, set) - ft_skipb(s1, set) + 1)));
}
