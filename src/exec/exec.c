/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:54:27 by Camille           #+#    #+#             */
/*   Updated: 2026/04/07 17:56:59 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

int	exec(t_minishell *sh, int nb_cmds)
{
	int	i;
	int	next;

	i = 0;
	next = 1;
	while (i < nb_cmds)
	{
		set_redirections(sh->cmds[i], sh->ios[i]);
		if (next != nb_cmds)
			set_pipe(&sh->cmds[i]->fds[1], &sh->cmds[next]->fds[0]);
		// make_child
		i++;
		next++;
	}
	//TODO:get_cmds_paths avec getenv
	//TODO:get exit code
	//TODO: free all ou liam free all avant de re-remplir
	return (sh->exit_code);
}
