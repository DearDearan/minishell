/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:54:50 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 16:13:19 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_minishell *sh, t_cmd *cmd)
{
	int	exit_c;

	if (sh->nb_cmds > 1)
		return (EXIT_SUCCESS);
	if (get_argc(cmd->argv) > 2)
	{
		ft_dprintf(2, "Syntax Error: more than 1 arguments.\n");
		return (EXIT_FAILURE);
	}
	else if (get_argc(cmd->argv) == 1)
	{
		cleaning(sh, sh->nb_cmds);
		exit(EXIT_SUCCESS);
	}
	else
		exit_c = ft_atoi(cmd->argv[1]);
	if (exit_c < 0 || exit_c > 255)
	{
		cleaning(sh, sh->nb_cmds);
		exit(exit_c % 256);
	}
	cleaning(sh, sh->nb_cmds);
	exit(exit_c);
}
