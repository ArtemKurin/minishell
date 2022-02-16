/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1pwd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:27:26 by mjodge            #+#    #+#             */
/*   Updated: 2022/01/29 14:45:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	else
		exit(1);
}
