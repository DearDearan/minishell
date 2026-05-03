/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:49:58 by Camille           #+#    #+#             */
/*   Updated: 2026/04/27 16:34:53 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_io(char *path, int flags, bool to_read, bool *io_is_invalid);
static int	get_fd_heredoc(t_minishell *sh, char *limiter, int size);
static void	heredoc_loop(char *s, char *limiter, int size, int (*fds)[2]);

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
	char	*line;

	if (pipe(fds) == -1)
		error_exit(sh, sh->nb_cmds);
	line = NULL;
	set_signals(true);
	heredoc_loop(line, limiter, size, &fds);
	set_signals(false);
	free(line);
	close(fds[1]);
	return (fds[0]);
}

static void	heredoc_loop(char *s, char *limiter, int size, int (*fds)[2])
{
	int	line_nb;
	int	fd_writing;
	int	fd_stdin_dup;

	line_nb = 1;
	fd_writing = (*fds)[1];
	fd_stdin_dup = dup(STDIN_FILENO);
	while (1)
	{
		s = readline("> ");
		if (g_signal == SIGINT)
		{
			dup2(fd_stdin_dup, STDIN_FILENO);
			close(fd_stdin_dup);
			close_fd(&(*fds)[0]);
			break ;
		}
		if (!s)
			printf(WARN_EOF, "minishell: warning: here-document", line_nb, limiter);
		if (!s || ((int)ft_strlen(s) == size && !ft_strncmp(s, limiter, size)))
			break ;
		ft_dprintf(fd_writing, "%s\n", s);
		free(s);
		line_nb++;
	}
}
