/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:53:30 by Camille           #+#    #+#             */
/*   Updated: 2026/04/12 12:31:40 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleaning(t_minishell *sh, int nb_cmds)
{
	cleaning_for_next_prompt(sh, nb_cmds);
	ft_free_strs(sh->envp);
}

void	cleaning_for_next_prompt(t_minishell *sh, int nb_cmds)
{
	int		i;
	t_io	*io;
	t_io	*old_io;

	i = 0;
	while (i < nb_cmds)
	{
		free(sh->cmds[i]->path);
		ft_free_strs(sh->cmds[i]->argv);
		close_fds(&sh->cmds[i]->fds);
		free(sh->cmds[i]);
		io = sh->ios[i];
		while (io)
		{
			old_io = io;
			free(io->infile);
			free(io->outfile);
			io = io->next;
			free(old_io);
		}
		i++;
	}
	free(sh->cmds);
	free(sh->ios);
}

void	error_exit(t_minishell *sh, int nb_cmds)
{
	perror("minishell");
	cleaning(sh, nb_cmds);
	exit(EXIT_FAILURE);
}
