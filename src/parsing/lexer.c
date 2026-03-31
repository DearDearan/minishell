/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:44:49 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/31 16:11:21 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/03/31 16:03:27 by lifranco         ###   ########.fr       */
>>>>>>> d56ba79 (feat!: Trying to do a lexer, did if there's no quotes, working on a split_quotes rn (help i wanna break my screen)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer *lex(char *argv)
{
	t_lexer *new;
	char	**args;
	int		i;
	bool	pipes;

	i = 0;
	if (count_quotes % 2 == 0)
		args = ""; // will have to write something
	else
		args = ft_split(argv, ' ');
	while (args[i])
	{
		if (args[i] == '|')
			pipes = true;
		if (args[i] != '|')
			new->content = args[i];
		new->type = get_type(args[i], pipes)
		i++;
		new->next;
	}
	new->next = NULL;
	return (new);
}

void get_type(char *arg, int pipe)
{


}