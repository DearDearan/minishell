/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:44:49 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/01 19:07:58 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_lst_addback(t_lexer **lst, t_lexer *node)
{
	t_lexer	*last;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	last = ft_lexlast(*lst);
	last->next = node;
}


static t_lexer	*ft_newnode(void *content)
{
	t_lexer	*node;

	node = ft_calloc(sizeof(t_lexer), 1);
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
	node->next = NULL;
	return (node);
}

static int get_type(char *arg, int delim)
{
	int i;

	i = 0;
	if (arg[i] == '<' || arg[i] == '>')
	{
		if (arg[i + 1] == arg[i] && arg[i] == '<')
			return (LIM);
		else if (arg[i + 1] == arg[i] && arg[i] == '>')
			return (APP);
		else if (arg[i] == '<')
			return (IN);
		else
			return (OUT);
	}
	else if (arg[i] == '|')
		return (PIPES);
	else if (delim > PIPES)
		return (FILENAME);
	else
		return (WORDS);
}

t_lexer *lex(char *argv)
{
	t_lexer	*new;
	t_lexer	*ret_lex;
	char	**args;
	int		i;
	int		type;

	i = 0;
	type = 0;
	ret_lex = NULL;
	args = ft_split_outquote(argv, ' ');
	if (!args)
		return (NULL);
	while (args && args[i])
	{
		new = ft_newnode(args[i]);
		if (!new)
			return (NULL);
		type = get_type(args[i], type);
		new->type = type;
		ft_lst_addback(&ret_lex, new); 
		i++;
	}
	ft_free_strs(args);
	return (ret_lex);
}
