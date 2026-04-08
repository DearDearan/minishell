/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:31:30 by Camille           #+#    #+#             */
/*   Updated: 2026/04/10 15:50:16 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define WARN_EOF \
	"minishell: warning: here-document delimited by end-of-file (wanted '%s')"

# include "minishell.h"

//exec.c
int		exec(t_minishell *sh, int nb_cmds);

// redirections.c
bool	set_redirections(t_minishell *sh, t_cmd *cmd, t_io *io);

// pipes.c
void	set_pipe(t_minishell *sh, int *curr_cmd_fd_out, int *next_cmd_fd_in);
void	close_fds(int (*fds)[2]);
void	close_fd(int *fd);

// children.c
//int		make_child(t_cmd *cmd);

//cleaning.c
void	cleaning(t_minishell *sh, int nb_cmds);
void	error_exit(t_minishell *sh, int nb_cmds);

#endif
