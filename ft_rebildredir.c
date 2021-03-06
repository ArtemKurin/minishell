/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rebildredir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:23 by acash             #+#    #+#             */
/*   Updated: 2022/01/29 22:52:35 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strrchr_upred(char *s, int c)
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
			return (1);
		}
	}
	return (0);
}

void	ft_create_l(t_infor *st, char *s, int index)
{
	int		i;
	int		len;
	char	*buffer;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == '<')
		{
			len = find_name_len(s, i, '<');
			buffer = ft_rebilder(st, i, len, index);
			st->commands[index - 1] = \
			ft_gnlstrjoin(st->commands[index - 1], buffer);
			if (buffer != NULL)
				free(buffer);
			if (st->commands[index - 1][0] == ';')
				st->commands[index - 1] = ft_skipsimic(st->commands[index - 1]);
			break ;
		}
		i--;
	}
}

void	ft_create_ll(t_infor *st, char *s, int index)
{
	int		i;
	int		len;
	char	*buffer;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<' && s[i + 1] == '<')
		{
			len = find_name_len(s, i, '<');
			buffer = ft_rebilder(st, i, len, index);
			st->commands[index - 1] = \
				ft_gnlstrjoin(st->commands[index - 1], buffer);
			if (buffer)
				free(buffer);
			if (st->commands[index - 1][0] == ';')
				st->commands[index - 1] = ft_skipsimic(st->commands[index - 1]);
			break ;
		}
		i++;
	}
}

void	ft_create_r(t_infor *st, char *s, int k)
{
	int		i;
	int		len;
	char	*buffer;
	int		f;

	i = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] == '>')
		{
			len = find_name_len(s, i, '>');
			buffer = ft_rebilder(st, i, len, k);
			if (st->commands[k + 1])
				free(st->commands[k + 1]);
			st->commands[k + 1] = buffer;
			while ((st->commands[k + 1][f] == '>'
				|| st->commands[k + 1][f] == ' ') && st->commands[k + 1][f])
				f++;
			open_file_h(st->commands[k + 1], \
				&st->commands[k + 1][f], 0);
			break ;
		}
		i++;
	}
}

void	ft_rebildredir(t_infor *st)
{
	int	i;

	i = 1;
	while (st->commands[i])
	{
		if (st->commands[i][0] != ';')
		{
			while (ft_strnstr(st->commands[i], "<<", \
				ft_strlen(st->commands[i])))
				ft_create_ll(st, st->commands[i], i);
			while (ft_strrchr_upred(st->commands[i], '<'))
				ft_create_l(st, st->commands[i], i);
			while (ft_strrchr_upred(st->commands[i], '>'))
				ft_create_r(st, st->commands[i], i);
		}
		if (st->commands[i + 1] && st->commands[i + 2])
			i += 2;
		if (st->commands[i + 1] != NULL)
			i++;
		if (st->commands[i + 1] != NULL)
			i++;
		else
			break ;
	}
}
