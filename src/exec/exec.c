/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:54:27 by Camille           #+#    #+#             */
/*   Updated: 2026/04/02 12:05:51 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

int	exec(t_minishell *sh, int nb_cmds)
{
	int	i;
	int	next;

	i = 0;
	while (i < nb_cmds)
	{
		next++;
		set_redirections(sh->cmds[i], sh->ios[i]);
		if (next != nb_cmds)
			set_pipe(sh->cmds[i], sh->cmds[next]);
		// make_child
		i++;
	}
	//TODO:get_cmds_paths avec getenv
	//TODO:get exit code
	//TODO: free all ou liam free all avant de re-remplir
	return (sh->exit_code);
}
