/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/02 16:08:02 by lifranco         ###   ########.fr       */
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

static int  count_words(t_lexer *lexed)
{
int count;
    count = 0;
while(lexed && lexed->type != PIPES)
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

void	fill_cmds(t_bushell *parsing, t_lexer *lexed)
{
	int		j;
	int 	i;

	i = 0;
	j = 0;
	parsing->cmds[i]->argv = ft_calloc(count_words(lexed) + 1, sizeof(char *));
	while (lexed)
	{
		if (lexed->type == WORDS)
		{
			parsing->cmds[i]->argv[j] = lexed->content;
			lexed = lexed->next;
			j++;
		}
		else if (lexed->type == PIPES )
		{
			i++;
			lexed = lexed->next;
			parsing->cmds[i]->argv = ft_calloc(count_words(lexed) + 1,
				sizeof(char *));
			j = 0;
		}
		else
			lexed = lexed->next;
	}
}

t_bushell *parse(char *line, char **envp)
{
	t_bushell		*parsing;
	t_lexer			*lexed;
	int 			i;

	lexed = lex(line);
	i = -1;
	parsing = ft_calloc(1, sizeof(t_bushell));
	parsing->nb_cmds = count_pipes(lexed) + 1;
	parsing->cmds = ft_calloc(parsing->nb_cmds, sizeof(t_cmd *));
	while (++i < parsing->nb_cmds)
	{
		parsing->cmds[i] = ft_calloc(1, sizeof(t_cmd));
		init_cmd(parsing->cmds[i]);
	}
	i = -1;
	fill_cmds(parsing, lexed);	
 	return (parsing);
}
