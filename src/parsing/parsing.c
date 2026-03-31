/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/31 16:19:47 by lifranco         ###   ########.fr       */
=======
/*   Updated: 2026/03/31 14:17:51 by lifranco         ###   ########.fr       */
>>>>>>> 85ebb81 (feat: To change, initialized cmd to -1 for fds unutilized)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
t_cmd *parse(int argc, char **argv, char **envp)
=======

t_cmd *parse(char *line, t_lexer)
>>>>>>> 85ebb81 (feat: To change, initialized cmd to -1 for fds unutilized)
{
	int 	i;
	char	**cmds;
    t_cmd	*parsing;

	parsing.fds[0] = -1;
	parsing.fds[1] = -1;
	parsing.pid = -1;
	i = 0;
	parsing = ft_calloc(argc, sizeof(t_cmd));
	cmds = ft_calloc(sizeof(char *), argc);
	while (i < argc)
	{
		cmds[i] = ft_split(argv[i + 1], ' ');
		i++;
	}

 	return (parsing);
}
