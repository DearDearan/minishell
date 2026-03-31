/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:52:32 by Camille           #+#    #+#             */
/*   Updated: 2026/04/02 12:06:49 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	sh;
	t_io		io1, io2, io3;
	t_cmd		cmd1, cmd2, cmd3;
	sh.envp = envp, (void)argc, (void)argv, sh.nb_cmds = 3, sh.cmds = ft_calloc(sh.nb_cmds, sizeof(t_cmd *)), ft_calloc(sh.nb_cmds, sizeof(t_io *));
	
	sh.cmds[0] = &cmd1, sh.cmds[1] = &cmd2, sh.cmds[2] = &cmd3;
	sh.ios[0] = &io1, sh.ios[1] = &io2, sh.ios[2] = &io3;

	cmd1.path = NULL, cmd2.path = NULL, cmd3.path = NULL;

	cmd1.argv = (char *[]){"ls", NULL};
	cmd2.argv = (char *[]){"cat", "-e", NULL};
	cmd3.argv = (char *[]){"cat", "-e", NULL};

	cmd1.fds[0] = -1, cmd2.fds[0] = -1, cmd3.fds[0] = -1;
	cmd1.fds[1] = -1, cmd2.fds[1] = -1, cmd3.fds[1] = -1;
	cmd1.pid = -1, cmd2.pid = -1, cmd3.pid = -1;

	io1.infile = NULL, io1.outfile = NULL, io1.is_lim = false, io1.outfile_flags = O_CREAT | O_TRUNC | O_WRONLY, io1.next = &io2;
	io2.infile = NULL, io2.outfile = NULL, io2.is_lim = false, io2.outfile_flags = O_CREAT | O_TRUNC | O_WRONLY, io2.next = &io3;
	io3.infile = NULL, io3.outfile = NULL, io3.is_lim = false, io3.outfile_flags = O_CREAT | O_TRUNC | O_WRONLY, io3.next = NULL;

	exec(&sh, sh.nb_cmds);
	return (0);
}
