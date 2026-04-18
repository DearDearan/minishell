/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/18 15:21:53 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	cmd->path = NULL;
	cmd->pid = -1;
	cmd->fds[0] = -1;
	cmd->fds[1] = -1;
	cmd->built_in = NULL;
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

static void fill_cmds(t_minishell *parse, t_lexer *lex)
{
    int i;

    i = 0;
    while (lex)
    {
        parse->cmds[i]->argv = ft_calloc(w_cnt(lex) + 1, sizeof(char *));
        if (!parse->cmds[i]->argv)
            error_exit(parse, parse->nb_cmds);
    	lex = fill_cmds_words(parse, lex, i);
        while (lex && lex->type != PIPES)
        {
            if (lex->type > PIPES)
                lex = process_io(parse, lex, i);
            else
                lex = lex->next;
        }
        if (lex && lex->type == PIPES)
            lex = lex->next;
        i++;
    }
}

void parse(char *line, t_minishell *parsing)
{
	t_lexer	*lexed;
	int 	i;
	int		j;

	lexed = lex(line);
	i = -1;
	parsing->nb_cmds = count_pipes(lexed) + 1;
	parsing->cmds = ft_calloc(parsing->nb_cmds, sizeof(t_cmd *));
	parsing->ios = ft_calloc(parsing->nb_cmds, sizeof(t_io *));
	if (!parsing->cmds || !parsing->ios)
		error_exit(parsing, parsing->nb_cmds);
	while (++i < (int) parsing->nb_cmds)
	{
		parsing->cmds[i] = ft_calloc(1, sizeof(t_cmd));
		parsing->ios[i] = ft_calloc(1, sizeof(t_io));
		if (!parsing->cmds[i] || !parsing->ios[i])
			error_exit(parsing, parsing->nb_cmds);
		init_cmd(parsing->cmds[i]);
	}
	i = 0;
	j = 0;
	fill_cmds(parsing, lexed);	
}
