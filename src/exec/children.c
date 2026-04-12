/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:48:49 by Camille           #+#    #+#             */
/*   Updated: 2026/04/12 14:18:06 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

static int	exit_child(t_minishell *sh, int nb_cmds);

void	make_child(t_minishell *sh, t_cmd *cmd)
{
	int	wstatus;

	cmd->pid = fork();
	if (!cmd->pid)
	{
		duplicate_fds(cmd);
		close_all_fds(sh->cmds, sh->nb_cmds);
		if (execve(cmd->path, cmd->argv, sh->envp) == -1)
			exit_child(sh, sh->nb_cmds);
	}
	else if (cmd->pid != -1)
	{
		wait_children(sh->cmds, sh->nb_cmds, &wstatus);
		error_exit(sh, sh->nb_cmds);
	}
}

void	wait_children(t_cmd **cmds, int nb_cmds, int *wstatus)
{
	int		i;

	i = 0;
	while (i < nb_cmds)
	{
		if (cmds[i]->pid != -1)
			waitpid(cmds[i]->pid, wstatus, 0);
		i++;
	}
}

static int	exit_child(t_minishell *sh, int nb_cmds)
{
	cleaning(sh, nb_cmds);
	return (EXIT_NOTFOUND);
}
