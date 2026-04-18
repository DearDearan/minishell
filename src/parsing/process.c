/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:49:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/18 15:47:24 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*process_word(char *content, t_minishell *parse)
{
	char	*expanded;
	char	*trim;

	expanded = expand(content, parse);
	if (!expanded)
		return (NULL);
	trim = trim_quotes(expanded);
	free(expanded);
	return (trim);
}

t_lexer *process_io(t_minishell *parse, t_lexer *lex, int cmd_i)
{
	if (!fill_io(parse, lex, cmd_i))
		return (NULL);
	return (lex->next->next);
}

t_lexer	*fill_cmds_words(t_minishell *parse, t_lexer *lex, int cmd_i)
{
	int	j;

	j = 0;
	while (lex && lex->type == WORDS)
	{
		parse->cmds[cmd_i]->argv[j] = process_word(lex->content, parse);
		if (!parse->cmds[cmd_i]->argv[j])
			error_exit(parse, parse->nb_cmds);
		j++;
		lex = lex->next;
	}
	return (lex);
}
