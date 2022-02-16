/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:10:49 by mjodge            #+#    #+#             */
/*   Updated: 2022/01/30 15:42:08 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipa_helper(char *arg, t_infor *st)
{
	if (!ft_strncmp("pwd ", arg, 4) || !ft_strncmp("pwd", arg, 4))
		ft_pwd();
	if (!ft_strncmp("env ", arg, 4) || !ft_strncmp("env", arg, 4))
		get_env(st);
	if (st->count != 1)
	{
		if (!ft_strncmp("export ", arg, 7) || !ft_strncmp("export", arg, 7))
			exit(ft_export(arg, st));
		if (!ft_strncmp("unset ", arg, 6) || !ft_strncmp("unset", arg, 6))
			exit(ft_unset(arg, st));
		if (!ft_strncmp("cd ", arg, 3) || !ft_strncmp("cd", arg, 3))
			exit(ft_cd(arg, st));
	}
	else
	{
		if (!ft_strncmp("export ", arg, 7) || !ft_strncmp("export", arg, 7) \
		|| !ft_strncmp("unset ", arg, 6) || !ft_strncmp("unset", arg, 6) \
		|| !ft_strncmp("cd ", arg, 3) || !ft_strncmp("cd", arg, 3))
			exit(0);
	}
	if (!ft_strncmp("echo ", arg, 5) || !ft_strncmp("echo", arg, 5))
		ft_echo(arg, st);
	return (0);
}

void	ft_reinit_pip(t_infor *st)
{
	close(st->pip.lpipe[0]);
	close(st->pip.lpipe[1]);
	close(st->pip.rpipe[0]);
	close(st->pip.rpipe[1]);
	close(st->pip.in);
	st->pip.lpipe[0] = -1;
	st->pip.lpipe[1] = -1;
	st->pip.rpipe[0] = -1;
	st->pip.rpipe[1] = -1;
	st->pip.in = -1;
}

void	ft_set_read(int *lpipe, int in)
{
	if (lpipe)
	{
		dup2(lpipe[0], STDIN_FILENO);
		close(lpipe[0]);
		close(lpipe[1]);
	}
	else
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
}

void	ft_set_write(int *rpipe, int out)
{
	if (rpipe)
	{
		dup2(rpipe[1], STDOUT_FILENO);
		close(rpipe[0]);
		close(rpipe[1]);
	}
	else
	{
		dup2(out, STDOUT_FILENO);
		close(out);
	}
}
