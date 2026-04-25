/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:49:58 by Camille           #+#    #+#             */
/*   Updated: 2026/04/10 15:45:14 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_io(char *path, int flags, bool to_read, bool *io_is_invalid);
static int	get_fd_heredoc(t_minishell *sh, char *limiter, int size);

bool	set_redirections(t_minishell *sh, t_cmd *cmd, t_io *io)
{
	while (io)
	{
		if (io->infile)
		{
			close_fd(&cmd->fds[0]);
			if (io->is_lim)
				cmd->fds[0] = get_fd_heredoc(sh, io->infile, ft_strlen(io->infile));
			else
				cmd->fds[0] = open_io(io->infile, O_RDONLY, true, &io->invalid);
			if (cmd->fds[0] == -1)
				return (false);
		}
		if (io->outfile)
		{
			close_fd(&cmd->fds[1]);
			cmd->fds[1] = open_io(io->outfile, io->outfile_flags, false, &io->invalid);
			if (cmd->fds[1] == -1)
				return (false);
		}
		io = io->next;
	}
	return (true);
}

static int	open_io(char *path, int flags, bool to_read, bool *io_is_invalid)
{
	int	fd;

	if (to_read)
		fd = open(path, flags);
	else
		fd = open(path, flags, 0644);
	if (fd == -1)
	{
		perror("minishell");
		*io_is_invalid = true;
	}
	return (fd);
}

static int	get_fd_heredoc(t_minishell *sh, char *limiter, int size)
{
	int		fds[2];
	char	*s;

	if (pipe(fds) == -1)
		error_exit(sh, sh->nb_cmds);
	s = NULL;
	while (1)
	{
		s = readline("> ");
		if (!s || ((int)ft_strlen(s) == size && !ft_strncmp(s, limiter, size)))
			break ;
		ft_dprintf(fds[1], "%s\n", s);
		free(s);
	}
	free(s);
	close(fds[1]);
	return (fds[0]);
}
