/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/04/29 10:04:32 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/04/28 16:21:12 by lifranco         ###   ########.fr       */
>>>>>>> 9d46c56b3df1691c4f5d8e177049120261fe8a30
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
	cmd->argv = NULL;
}

int  w_cnt(t_lexer *lexed)
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
		parse->cmds[i]->argv = NULL;
        while (lex && lex->type != PIPES)
        {
			if (lex->type == WORDS)
				lex = fill_cmds_words(parse, lex, i);
            else if (lex->type > PIPES)
                lex = process_io(parse, lex, i);
            else
                lex = lex->next;
        }
        if (lex && lex->type == PIPES)
            lex = lex->next;
		if (!lex)
			break ;
		i++;
    }
}

int	parse(char *line, t_minishell *parsing)
{
	t_lexer	*lexed;
	int 	i;

	lexed = lex(line);
	i = -1;
	parsing->nb_cmds = count_pipes(lexed) + 1;
	parsing->cmds = ft_calloc(parsing->nb_cmds, sizeof(t_cmd *));
	parsing->ios = ft_calloc(parsing->nb_cmds, sizeof(t_io *));
	parsing->parse_err = false;
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
	fill_cmds(parsing, lexed);
	ft_lexclear(&lexed, del);
	if (parsing->parse_err == true)
		return (1);
	return (0);
}
