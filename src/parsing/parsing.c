/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/13 17:28:20 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_cmd(t_cmd *cmd)
{
	cmd->path = NULL;
	cmd->pid = -1;
	cmd->fds[0] = -1;
	cmd->fds[1] = -1;
}

static int  w_cnt(t_lexer *lexed)
{
	int count;
    count = 0;
	while (lexed && lexed->type != PIPES)
    {
		if (lexed->type == WORDS)
        	count++;
        lexed = lexed->next;
    }
	return (count);
}
static unsigned int	count_pipes(t_lexer *lexed)
{
	int count;

	count = 0;
	while(lexed)
	{
		if (lexed->type == PIPES)
			count++;
		lexed = lexed->next;
	}
	return (count);
}

static void	fill_cmds(t_minishell *parse, t_lexer *lex)
{
	int		j;
	int 	i;

	i = 0;
	j = 0;
	parse->cmds[i]->argv = ft_calloc(w_cnt(lex) + 1, sizeof(char *));
	while (lex)
	{
		if (lex->type == WORDS)
		{
			parse->cmds[i]->argv[j] = trim_quotes(expand(lex->content, parse));
			lex = lex->next;
			j++;
		}
		else if (lex->type == PIPES)
		{
			lex = lex->next;
			parse->cmds[++i]->argv = ft_calloc(w_cnt(lex) + 1, sizeof(char *));
			j = 0;
		}
		else if (lex->type > PIPES)
			lex = fill_io(parse, lex, i);
		else
			lex = lex->next;
	}
}

t_minishell *parse(char *line, char **envp)
{
	t_minishell		*parsing;
	t_lexer			*lexed;
	size_t 			i;

	lexed = lex(line);
	i = -1;
	parsing = ft_calloc(1, sizeof(t_minishell));
	if (!parsing)
		return (NULL);
	parsing->envp = envp;
	parsing->nb_cmds = count_pipes(lexed) + 1;
	parsing->cmds = ft_calloc(parsing->nb_cmds, sizeof(t_cmd *));
	parsing->ios = ft_calloc(parsing->nb_cmds, sizeof(t_io *));
	if (!parsing->cmds || !parsing->ios)
		return (NULL);
	while (++i < parsing->nb_cmds)
	{
		parsing->cmds[i] = ft_calloc(1, sizeof(t_cmd));
		parsing->ios[i] = ft_calloc(1, sizeof(t_io));
		if (!parsing->cmds[i] || !parsing->ios[i])
			return (NULL);
		init_cmd(parsing->cmds[i]);
	}
	fill_cmds(parsing, lexed);	
 	return (parsing);
}
