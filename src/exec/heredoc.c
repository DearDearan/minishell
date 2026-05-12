/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:59:17 by Camille           #+#    #+#             */
/*   Updated: 2026/05/08 15:39:20 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_loop(t_minishell *sh, char *s, char *lim, int (*fds)[2]);
static bool	sigint_triggered(int fd_stdin_dup, int (*fds)[2]);
static void	print_heredoc(t_minishell *sh, int fd_w, int fd_r, char *line);

int	get_fd_heredoc(t_minishell *sh, char *limiter)
{
	int		fds[2];
	char	*line;

	if (pipe(fds) == -1)
		error_exit(sh, sh->nb_cmds);
	line = NULL;
	set_signals(true);
	heredoc_loop(sh, line, limiter, &fds);
	ignore_signals();
	close(fds[1]);
	return (fds[0]);
}

static void	heredoc_loop(t_minishell *sh, char *s, char *lim, int (*fds)[2])
{
	int	size;
	int	line_nb;
	int	fd_writing;
	int	fd_stdin_dup;

	size = ft_strlen(lim);
	line_nb = 1;
	fd_writing = (*fds)[1];
	fd_stdin_dup = dup(STDIN_FILENO);
	while (1)
	{
		s = readline("> ");
		if (sigint_triggered(fd_stdin_dup, fds))
			break ;
		if (!s)
			printf(WARN_EOF, "minishell: warning: heredoc", line_nb, lim);
		if (!s || ((int)ft_strlen(s) == size && !ft_strncmp(s, lim, size)))
			break ;
		print_heredoc(sh, fd_writing, fd_stdin_dup, s);
		free(s);
		line_nb++;
	}
	free(s);
	close(fd_stdin_dup);
}

static bool	sigint_triggered(int fd_stdin_dup, int (*fds)[2])
{
	if (g_signal == SIGINT)
	{
		dup2(fd_stdin_dup, STDIN_FILENO);
		close(fd_stdin_dup);
		close_fd(&(*fds)[0]);
		return (true);
	}
	return (false);
}

static void	print_heredoc(t_minishell *sh, int fd_w, int fd_r, char *line)
{
	char	*expanded_line;

	expanded_line = expand(line, sh);
	if (!expanded_line)
	{
		free(line);
		close(fd_r);
		close(fd_w);
		error_exit(sh, sh->nb_cmds);
	}
	ft_dprintf(fd_w, "%s\n", expanded_line);
	free(expanded_line);
}
