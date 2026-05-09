/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:48:44 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/09 13:33:03 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_pipes(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

static size_t	count_spaces(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str && str[++i])
	{
		if (is_redir(str[i]) && !is_in_quotes(str, i))
		{
			if (i > 0 && str[i - 1] != ' ' && !is_redir(str[i - 1]))
				count++;
			if (str[i + 1] && str[i + 1] != ' ' && !is_redir(str[i + 1]))
				count++;
		}
		else if (is_pipes(str[i]) && !is_in_quotes(str, i))
		{
			if (i > 0 && str[i - 1] != ' ')
				count++;
			if (str[i + 1] && str[i + 1] != ' ')
				count++;
		}
	}
	return (count);
}

static void	add_spaces(char *line, char *new, int *i, int *j)
{
	if (is_redir(line[*i]) && !is_in_quotes(line, *i))
	{
		if (*i > 0 && line[*i - 1] != ' ' && !is_redir(line[*i - 1]))
		{
			new[(*j)++] = ' ';
		}
		new[(*j)++] = line[*i];
		if (line[*i + 1] && line[*i + 1] != ' '
			&& !is_redir(line[*i + 1]))
			new[(*j)++] = ' ';
	}
	else if (is_pipes(line[*i]) && !is_in_quotes(line, *i))
	{
		if (*i > 0 && line[*i - 1] != ' ')
			new[(*j)++] = ' ';
		new[(*j)++] = line[*i];
		if (line[*i + 1] && line[*i + 1] != ' ')
			new[(*j)++] = ' ';
	}
	else
		new[(*j)++] = line[*i];
	(*i)++;
}

char	*add_spaces_around_ops(char *line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(sizeof(char *), ft_strlen(line) + count_spaces(line) + 1);
	if (!new)
		error_parsing(NULL, NULL, 0);
	while (line && line[i])
		add_spaces(line, new, &i, &j);
	return (new);
}
