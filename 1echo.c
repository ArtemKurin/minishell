/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1echo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:09:03 by acash             #+#    #+#             */
/*   Updated: 2022/01/30 19:35:28 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *arg, t_infor *st)
{
	char	**splited;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	splited = ft_split_wquots(arg);
	if (!ft_strcmp(splited[i], "-n"))
	{
		i++;
		flag = 1;
	}
	while (splited[i])
	{	
		ft_putstr(splited[i]);
		i++;
		if (splited[i])
			ft_putchar_fd(' ', 1);
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
	(void)st;
	exit(0);
}
