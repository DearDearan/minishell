/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
/*   Updated: 2026/03/31 16:18:31 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd *parse(int argc, char **argv, char **envp)
{
	int 	i;
	char	**cmds;
    t_cmd	*parsing;

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
