/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:56:16 by mjodge            #+#    #+#             */
/*   Updated: 2022/01/30 20:15:20 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_minus_helper(char *prev_dir, t_infor *st)
{
	char	*current_dir;
	char	*tmp;

	current_dir = find_env("PWD=", st);
	tmp = prev_dir;
	prev_dir = ft_strjoin("export OLDPWD=", current_dir);
	ft_export(prev_dir, st);
	free(prev_dir);
	free(current_dir);
	current_dir = ft_strjoin("export PWD=", tmp);
	free(tmp);
	ft_export(current_dir, st);
	free(current_dir);
	set_envp(st);
	return (0);
}

void	ft_mshfree_helper(int exc, t_infor *st)
{
	if (exc == 2)
		g_error = 258;
	if (st->last_r)
	{
		free(st->last_r);
		st->last_r = NULL;
		st->pip.curr_index = 0;
	}
}

int	ft_mshfree1(t_infor *st, int code, int exc)
{
	int	i;

	if (code == 1)
	{
		if (st->line)
			free(st->line);
	}
	else if (code == 2)
	{
		if (st->line)
			free(st->line);
		i = 0;
		while (st->cmd[i])
		{
			ft_myfree(st->cmd[i]);
			i++;
		}
		if (st->cmd)
			free(st->cmd);
	}
	ft_mshfree_helper(exc, st);
	return (1);
}

void	ft_do_redir_left_deep(t_infor *st, int in)
{
	if (st->last_r[st->pip.curr_index] == 2)
	{
		close(in);
		in = open(".tmp", O_RDONLY, 0777);
		st->pip.in = in;
	}
}

int	ft_space_check(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}
