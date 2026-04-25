/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:49:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/25 13:49:30 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_quoted(char *content, int i)
{
	while (content[i])
	{
		if (content[i] == '\'')
			return (true);
		else if (content[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

char	**process_word(char *content, t_minishell *parse)
{
	char	*expanded;
	char	*trim;
	char	**ret;
	bool	is_quote;

	is_quote = is_quoted(content, 0);
	expanded = expand(content, parse);
	if (!expanded)
		error_exit(parse, parse->nb_cmds);
	trim = trim_quotes(expanded);
	free(expanded);
	if (is_quote == false)
		ret = ft_split_outquote(trim, ' ');
	else
	{
		ret = ft_calloc(1, sizeof(char *));
		ret[0] = ft_strdup(trim);
	}
	free(trim);
	return (ret);
}

t_lexer *process_io(t_minishell *parse, t_lexer *lex, int cmd_i)
{
	if (!fill_io(parse, lex, cmd_i))
		return (NULL);
	return (lex->next);
}

t_lexer	*fill_cmds_words(t_minishell *parse, t_lexer *lex, int cmd_i)
{
	int		j;
	char	**words;
	int		k;

	j = 0;
	while (lex && lex->type == WORDS)
	{
		k = 0;
		words = process_word(lex->content, parse);
		while (words && words[k])
		{
			fill_argv(parse, parse->cmds[cmd_i], words[k]);
			k++;
		}
		ft_free_strs(words);
		lex = lex->next;
	}
	return (lex);
}
	