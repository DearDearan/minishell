/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:54:50 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/21 11:45:48 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

int ft_exit(t_minishell *sh, t_cmd *cmd)
{
	int	exit_c;

	if (count_args(cmd->argv) > 2)
	{
		ft_dprintf(2, "Syntax Error: more than 1 arguments.\n");
		return (-1);
	}
	else if (count_args(cmd->argv) == 1)
	{
		cleaning(sh, sh->nb_cmds);
		exit(0);
	}
	else
		exit_c = ft_atoi(cmd->argv[1]);
	if (exit_c < 0 || exit_c > 255)
	{
		cleaning(sh, sh->nb_cmds);
		exit(0);
	}
	cleaning(sh, sh->nb_cmds);
	exit(exit_c);
}
