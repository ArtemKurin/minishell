/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1env.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:35:47 by mjodge            #+#    #+#             */
/*   Updated: 2022/01/29 19:43:58 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_envp(t_infor *st)
{
	int		count;
	char	**new_env;
	t_vars	*dup;
	int		i;

	count = ft_lstsize(st->vars);
	new_env = malloc(sizeof(char *) * (count + 1));
	if (!new_env)
		return (ft_error(st, 1));
	new_env[count] = NULL;
	dup = st->vars;
	i = 0;
	while (dup)
	{
		new_env[i++] = ft_strdup(dup->var);
		dup = dup->next;
	}
	if (st->env)
		ft_myfree(st->env);
	st->env = new_env;
	return (1);
}

void	get_env(t_infor *st)
{
	t_vars	*dup;

	dup = st->vars;
	while (dup)
	{
		ft_putstr(dup->var);
		ft_putchar_fd('\n', 1);
		dup = dup->next;
	}
	exit(0);
}
