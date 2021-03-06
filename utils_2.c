/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:00:17 by mjodge            #+#    #+#             */
/*   Updated: 2022/01/30 18:19:38 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strrchr_deep(char *s, int c)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = ft_strlen(s) + 1;
	is_it_quot(' ', 1);
	while (i--)
	{
		if ((is_it_quot(b[i], 0) == 0) && b[i] == (char) c)
		{
			return (i);
		}
	}
	return (0);
}

void	ft_last_redd(t_infor *st, char *s, int index)
{
	int	j;

	j = -1;
	j = ft_strrchr_deep(s, '<');
	if (j != 0)
	{
		if (s[j - 1] == '<')
			st->last_r[index] = 2;
		else
			st->last_r[index] = 1;
	}
	else
		st->last_r[index] = 1;
}

void	ft_last_red(t_infor *st, char **s)
{
	int	iinc[3];

	iinc[0] = 0;
	iinc[2] = 0;
	while (s[iinc[0]])
	{
		iinc[2]++;
		iinc[0]++;
	}
	iinc[0] = 0;
	iinc[1] = 0;
	st->last_r = malloc((sizeof(int) + 1) * iinc[2] / 2);
	if (st->last_r == NULL)
		ft_error(st, 1);
	while (s[iinc[0]])
	{
		while (s[iinc[0]] && (s[iinc[0]][0] == ';' || s[iinc[0]][0] == '|'))
			iinc[0]++;
		if (!s[iinc[0]])
			break ;
		ft_last_redd(st, s[iinc[0]], iinc[1]);
		iinc[0]++;
		iinc[1]++;
	}
}

int	ft_getlen(char *splited)
{
	int		len;

	len = 0;
	while (splited && splited[len] && splited[len] != '=')
		len++;
	return (len);
}

int	ft_changevar(char **splited, t_vars **vars, int len)
{
	(void)len;
	free((*vars)->var);
	(*vars)->var = ft_strdup(*splited);
	return (0);
}
