/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:07:37 by mjodge            #+#    #+#             */
/*   Updated: 2022/01/30 18:40:52 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// закрыть трубу вправо
#include "minishell.h"

void	redirect_r(char *cmd, t_infor *st)
{
	int	out;

	out = -1;
	(void)st;
	if (!ft_strncmp(cmd, ">>", 2))
	{
		while (*cmd == '>' || *cmd == ' ')
			cmd++;
		out = open(cmd, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	else
	{
		while (*cmd == '>' || *cmd == ' ')
			cmd++;
		out = open(cmd, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	ft_set_write(NULL, out);
}

int	redirect_l(char *cmd, t_infor *st)
{
	close(st->pip.in);
	if (!ft_strncmp(cmd, "<<", 2))
	{
		while (*cmd == '<' || *cmd == ' ')
			cmd++;
		here_doc(cmd);
		st->pip.in = open(".tmp", O_RDONLY, 0777);
	}
	else
	{
		while (*cmd == '<' || *cmd == ' ')
			cmd++;
		st->pip.in = open(cmd, O_RDONLY, 0777);
		if (st->pip.in == -1)
		{
			ft_putstr_fd("msh: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			exit(errno);
		}
	}
	return (st->pip.in);
}

void	here_doc(char *limiter)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(limiter, line) || !line)
		{
			close(fd);
			free(line);
			return ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	return ;
}

int	open_file_h(char *redir, char *file, int flag)
{
	int	fd;

	fd = -2;
	if (!ft_strncmp(redir, ">>", 2) && file)
		fd = open(file, \
		O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (!ft_strncmp(redir, ">", 1) && file)
		fd = open(file, \
		O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!flag)
		close(fd);
	return (fd);
}
