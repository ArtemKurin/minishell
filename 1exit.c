/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:08:03 by acash             #+#    #+#             */
/*   Updated: 2022/01/30 19:59:03 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strisdig(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": numeric argument required", 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
	}
	return (1);
}

void	ft_exit(char *argv, t_infor *st)
{
	char	**splited;

	splited = ft_split_wquots(argv);
	if (splited[1] && splited[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments", 2);
		ft_putchar_fd('\n', 2);
		exit(ft_atoi(splited[1]));
	}
	if (splited[1] && !ft_strisdig(splited[1]))
		st->exit = 255;
	else if (splited[1])
		st->exit = ft_atoi(splited[1]);
	else
		st->exit = 1;
	ft_myfree(splited);
	exit(st->exit);
}
