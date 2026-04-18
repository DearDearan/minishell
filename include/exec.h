/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:31:30 by Camille           #+#    #+#             */
/*   Updated: 2026/04/17 17:50:12 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define WARN_EOF \
	"minishell: warning: here-document delimited by end-of-file (wanted '%s')"
# define EXIT_NOTFOUND 127

# include "structs.h"

// exec.c
int		exec(t_minishell *sh, int nb_cmds);

// built-in.c
bool	set_built_in(t_cmd *cmd, char *bin);
int		test(t_minishell *sh, t_cmd *cmd);//TODO:a delete + tard

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

// exit_code.c
int		get_exit_code(pid_t last_cmd_pid, int wstatus);
int		parse_wait_status(int wstatus);

#endif
