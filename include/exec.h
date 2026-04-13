/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:31:30 by Camille           #+#    #+#             */
/*   Updated: 2026/04/14 15:30:25 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define WARN_EOF \
	"minishell: warning: here-document delimited by end-of-file (wanted '%s')"
# define EXIT_NOTFOUND 127

# include "structs.h"

//exec.c
int		exec(t_minishell *sh, int nb_cmds);

// redirections.c
bool	set_redirections(t_minishell *sh, t_cmd *cmd, t_io *io);

// fds_utils.c
void	close_fds(int (*fds)[2]);
void	close_fd(int *fd);
void	duplicate_fds(t_cmd *cmd);
void	close_all_fds(t_cmd **cmds, int nb_cmds);

// pipes.c
void	set_pipe(t_minishell *sh, int *curr_cmd_fd_out, int *next_cmd_fd_in);

// children.c
void	make_child(t_minishell *sh, t_cmd *cmd);
void	wait_children(t_cmd **cmds, int nb_cmds, int *wstatus);

#endif
