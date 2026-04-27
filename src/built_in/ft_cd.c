/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:19:39 by Camille           #+#    #+#             */
/*   Updated: 2026/04/25 16:55:27 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	can_execute_cd(int nb_cmds, char **argv);

int	ft_cd(t_minishell *sh, t_cmd *cmd)
{

	if (!can_execute_cd(sh->nb_cmds, cmd->argv))
		return (EXIT_FAILURE);
	//ft_setenv("PWD", cmd->argv[1]);//TODO:attendre fonction de liam ft_setenv
	return (EXIT_SUCCESS);
}

static bool	can_execute_cd(int nb_cmds, char **argv)
{
	if (nb_cmds > 1)
		return (false);
	if (get_argc(argv) > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (false);
	}
	if (chdir(argv[1]) == -1)
	{
		perror("minishell");
		return (false);
	}
	return (true);
}
