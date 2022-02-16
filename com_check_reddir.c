/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_check_reddir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:44:34 by acash             #+#    #+#             */
/*   Updated: 2022/01/29 21:36:28 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err_redd(char *s, int i)
{
	int	j;

	is_it_quot(' ', 1);
	while (s[i + 1] == ' ' && s[i + 1])
		i++;
	j = i + 1;
	if (s[i + 1] == '>' || s[i + 1] == '|'
		|| s[i + 1] == '<' || !s[i + 1])
		return (0);
	if (ft_isdigit(s[j]) && s[j - 1] == '>' && s[j + 1] == '>')
		return (0);
	return (1);
}

int	ft_check_reddir(t_infor *st)
{
	int	i;

	i = 0;
	while (st->line[i])
	{
		if (st->line[i] == '>' || st->line[i] == '<')
		{
			if ((st->line[i + 1] == '>' && st->line[i] == '>')
				|| (st->line[i + 1] == '<' && st->line[i] == '<'))
			{
				if (err_redd(st->line, i + 1) == 0)
					return (1);
				i++;
			}
			else
			{
				if (err_redd(st->line, i) == 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}
