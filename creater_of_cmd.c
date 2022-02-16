/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creater_of_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:32:29 by acash             #+#    #+#             */
/*   Updated: 2022/01/29 20:07:03 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_com_count(char **s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s && s[i])
		count = 1;
	while (s && s[i])
	{
		if (s[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

char	**ft_create_node(t_infor *st, int *j)
{
	int		i;
	int		tmp;
	int		len;
	char	**nl;

	i = (*j);
	len = 0;
	while (st->commands[i] && st->commands[i][0] != '|')
	{
		i++;
		len++;
	}
	tmp = (*j);
	(*j) = i + 1;
	nl = ft_calloc(len + 1, sizeof(char *));
	if (nl == NULL)
		ft_error(NULL, 1);
	i = 0;
	while (i + tmp < tmp + len)
	{
		nl[i] = ft_strdup(st->commands[tmp + i]);
		i++;
	}
	nl[i] = NULL;
	return (nl);
}

char	***ft_createrofcmd(t_infor *st)
{
	char	***nl;
	int		i;
	int		len;
	int		order;

	i = 0;
	order = 0;
	nl = NULL;
	len = find_com_count(st->commands);
	if (len != 0)
	{
		nl = ft_calloc(len + 1, sizeof(char **));
		if (nl == NULL)
			ft_error(NULL, 1);
		while (i < len)
		{
			nl[i] = ft_create_node(st, &order);
			i++;
		}
		nl[i] = NULL;
	}
	return (nl);
}
