/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:49:58 by Camille           #+#    #+#             */
/*   Updated: 2026/04/07 17:56:49 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"

static int	open_io(char *path, int flags);
static int	get_fd_heredoc(char *limiter, int size);

void	set_redirections(t_cmd *cmd, t_io *io)
{
	if (io->infile)
	{
		if (io->is_lim)
			cmd->fds[0] = get_fd_heredoc(io->infile, ft_strlen(io->infile));
		else
			cmd->fds[0] = open_io(io->infile, O_RDONLY);
	}
	if (io->outfile)
		cmd->fds[1] = open_io(io->infile, io->outfile_flags);
}

static int	open_io(char *path, int flags)
{
	int	fd;

	fd = open(path, flags);
	if (fd == -1)
		perror("minishell");
	return (fd);
}

static int	get_fd_heredoc(char *limiter, int size)
{
	int		fds[2];
	char	*s;

	if (pipe(fds) == -1)
		exit(EXIT_FAILURE); //TODO: liam clean_exit fonction
	s = NULL;
	while (1)
	{
		s = readline("> ");
		if (!s || ((int)ft_strlen(s) == size && !ft_strncmp(s, limiter, size)))
			break ;
		ft_dprintf(fds[1], s);
		free(s);
	}
	free(s);
	close(fds[1]);
	return (fds[0]);
}
